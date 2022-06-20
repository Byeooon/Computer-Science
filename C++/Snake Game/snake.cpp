#include <ncurses.h>
#include <locale.h>
#include <list>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unistd.h>


using namespace std;

WINDOW *gameWindow, *scoreWindow, *missionWindow;
int **gameMap;
int gameWindow_row=30, gameWindow_col=100;
int scoreWindow_row=15, scoreWindow_col=28;
int missionWindow_row=13, missionWindow_col=28;
char snakeDirection[] = {'r', 'd', 'l', 'u'};
list<pair<int,int>> snake;
vector<pair<int,int>> wall;
pair<int,int> snakeHead, copyHead, growthItem, poisonItem, boostItem, gate1, gate2;
int keyPressed, direction = 'r';
int timeDelay = 200000; //5fps
int growthItemCount, poisonItemCount, boostItemCount, gateCount;
bool stageClear = false;
time_t time_growth, time_poison, time_boost, time_gate, playTime;

void playGame(int g, int p, int b, int gate);
void makeMap(int gameRound);
bool makeSnake();
void wallSearch();
void drawMap();
void drawScore(int g, int p, int b, int gate);
void drawMission(int g, int p, int b, int gate);
void addBoostItem();
void addGrowthItem();
void addPoisonItem();


int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "");

    initscr(); // ncurses모드시작
    curs_set(0); // 커서 가리기
    resize_term(50, 200); // 창크기 설정

    start_color(); // Color사용선언
    init_color(COLOR_CYAN, 0, 0, 0);
    init_pair(1, COLOR_WHITE, COLOR_CYAN);//색attribute 설정
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    bkgd(COLOR_PAIR(1));
    refresh();

    int gameRound, g=1, p=1, b=1, gate=1;
    for(gameRound=1; gameRound<5; gameRound++) {
        stageClear = false;
        playTime = time(NULL); // 게임시작시간
        wall.clear(); // 벽초기화
        snake.clear(); // 지렁이 초기화
        timeDelay = 200000;
        growthItemCount = 0;
        poisonItemCount = 0;
        boostItemCount = 0;
        gateCount = 0;

        nodelay(stdscr, TRUE); // 딜레이없이 키입력 가능
        keypad(stdscr, TRUE); // 방향키 입력 가

        direction = 'r';

        makeMap(gameRound);
        // 지렁이 초기 위치
        snake.push_back({5, 4});
        snake.push_back({5, 6});
        snake.push_back({5, 8});
        gameMap[5][4] = 3;
        gameMap[5][6] = 3;
        gameMap[5][8] = 3;
        snakeHead = {5, 8};

        addGrowthItem();
        addBoostItem();
        addPoisonItem();

        playGame(g, p, b, gate);

        clear();

        nodelay(stdscr, FALSE);
        keypad(stdscr, FALSE);

        if(stageClear == false) {
            break;
        }
        if(gameRound < 4) {
            mvprintw(20, 40, "Stage [%d] Clear! Press \"ENTER\" to Next Stage", gameRound);
            while(getch() != 10);
        }
        refresh();
        g++; p++; b++; gate++;
    }

    if(gameRound != 5) {
        mvprintw(10, 20, "!!!   MISSION FAIL  !!!");
        mvprintw(11, 20, "TRY AGAIN! Press \"ENTER\"");
    } else {
        mvprintw(10, 20, "!!!!!!!       CONGRATULATIONS       !!!!!!!");
        mvprintw(11, 20, "All stages completed! Press \"ENTER\" to QUIT");
    }

    refresh();
    while(getch() != 10);
    endwin();

    return 0;
}

void makeMap(int gameRound) {
    gameWindow = newwin(gameWindow_row, gameWindow_col, 4, 4);
    wbkgd(gameWindow, COLOR_PAIR(2));
    gameMap = new int*[gameWindow_row];
    for(int i=0; i<gameWindow_row; i++) {
        gameMap[i] = new int[gameWindow_col];
        gameMap[i][0] = 1;
        gameMap[i][gameWindow_col-2] = 1;
    }
    for(int i=2; i<gameWindow_col-2; i+=2) {
        gameMap[0][i] = 1;
        gameMap[gameWindow_row-1][i] = 1;
    }

    switch(gameRound) {
        case 1 :
            for(int i=gameWindow_col/4+1; i<gameWindow_col/4*3; i+=2) {
                gameMap[gameWindow_row/2-8][i] = 1;
                gameMap[gameWindow_row/2+7][i] = 1;
            }
            for(int i=gameWindow_row/2-7; i<gameWindow_row/2+3; i++) {
                gameMap[i][gameWindow_col/4+1] = 1;
                gameMap[i+4][gameWindow_col/4*3-1] = 1;
            }
            break;
        case 2 :
            for(int i=gameWindow_col/5; i<gameWindow_col/5*4; i+=2) {
                gameMap[gameWindow_row/2-1][i] = 1;
            }
            for(int i=gameWindow_row/5; i<gameWindow_row/5*4; i++) {
                gameMap[i][gameWindow_col/2] = 1;
            }
            gameMap[gameWindow_row/2-1][gameWindow_col/2] = 2; // immune wall
            break;
        case 3 :
            for(int i=1; i<gameWindow_row/5*3; i++){
                gameMap[i][gameWindow_col/3-1] = 1;
            }
            for(int i=gameWindow_row-1; i>gameWindow_row/5*2; i--){
                gameMap[i][gameWindow_col/3*2] = 1;
            }
            gameMap[0][gameWindow_col/3-1] = 2;
            gameMap[gameWindow_row-1][gameWindow_col/3*2] = 2;
            break;
        case 4 :
            for(int i=gameWindow_col/5-2; i<gameWindow_col/5*4+3; i+=2) {
                gameMap[gameWindow_row/2-8][i] = 1;
                gameMap[gameWindow_row/2+7][i] = 1;
            }
            for(int i=gameWindow_col/5+14; i<gameWindow_col/5*4-13; i+=2) {
                gameMap[gameWindow_row/2-8][i] = 0;
            }
            gameMap[gameWindow_row/2][gameWindow_col/2-4] = 1;
            gameMap[gameWindow_row/2][gameWindow_col/2+4] = 1;
            break;
    }
    // imune wall
    gameMap[0][0] = 2;
    gameMap[0][gameWindow_col-2] = 2;
    gameMap[gameWindow_row-1][0] = 2;
    gameMap[gameWindow_row-1][gameWindow_col-2] = 2;

    // wall list에 좌표 넣기
    for(int i=0; i<gameWindow_row; i++) {
        for(int j=0; j<gameWindow_col; j+=2) {
            if(gameMap[i][j] == 1) {
                wall.push_back({i, j});
            }
        }
    }
}

void drawMap() {
    for(int i=0; i<gameWindow_row; i++) {
        for(int j=0; j<gameWindow_col-1; j+=2) {
            if(gameMap[i][j]==1) { // wall
                mvwprintw(gameWindow, i, j, "\u2B1C");
            } else if(gameMap[i][j]==3) { // snake
                mvwprintw(gameWindow, i, j, "\u23f9");
            } else if(gameMap[i][j] == 4) { // growthItem
                mvwprintw(gameWindow, i, j, "\u2b50");
            } else if(gameMap[i][j] == 5) { // poisonItem
                mvwprintw(gameWindow, i, j, "\u26d4");
            } else if(gameMap[i][j] == 6) { // boostItem
                mvwprintw(gameWindow, i, j, "\u26a1");
            } else if(gameMap[i][j] == 7) {
                mvwprintw(gameWindow, i, j, "\u26e9");
            } else if(gameMap[i][j] == 2) {
                mvwprintw(gameWindow, i, j, "\u23fa");
            }
        }
    }
}
void drawScore(int growthMission, int poisonMission, int boostMission, int gateMission) {
    scoreWindow = newwin(scoreWindow_row, scoreWindow_col, 4, gameWindow_col+10);
    wbkgd(scoreWindow, COLOR_PAIR(2));
    mvwprintw(scoreWindow, 1, 0, "  \u203b \u203b \u203b  Score Board \u203b \u203b \u203b");

    mvwprintw(scoreWindow, 3, 0, "  \u23f9  (Length) ------ (%d)", snake.size());
    mvwprintw(scoreWindow, 5, 0, "  \u2b50 (Growth) ------ (%d)", growthItemCount);
    mvwprintw(scoreWindow, 7, 0, "  \u26d4 (Poison) ------ (%d)", poisonItemCount);
    mvwprintw(scoreWindow, 9, 0, "  \u26a1  (Boost) ------ (%d)", boostItemCount);
    mvwprintw(scoreWindow, 11, 0, "  \u26e9    (Gate) ------ (%d)", gateCount);
    if(growthItemCount>=growthMission && poisonItemCount>=poisonMission && boostItemCount>=boostMission && gateCount>=gateMission && snake.size()>=growthMission+3) {
        stageClear = true;
    }
    mvwprintw(scoreWindow, 13, 0, "           \u231b : %d", time(NULL) - playTime);
}

void drawMission(int growthMission, int poisonMission, int boostMission, int gateMission) {
    missionWindow = newwin(missionWindow_row, missionWindow_col, 21, gameWindow_col+10);
    wbkgd(missionWindow, COLOR_PAIR(2));
    mvwprintw(missionWindow, 1, 0, "   \u203b \u203b \u203b   MISSION  \u203b \u203b \u203b");

    if(snake.size() < 3+growthMission)
        mvwprintw(missionWindow, 3, 0, "  \u23f9  (Length) -------- (%d)", growthMission+3);
    else
        mvwprintw(missionWindow, 3, 0, "  \u23f9  (Length) -------- \u2705");

    if(growthItemCount < growthMission)
        mvwprintw(missionWindow, 5, 0, "  \u2b50 (Growth) -------- (%d)", growthMission);
    else
        mvwprintw(missionWindow, 5, 0, "  \u2b50 (Growth) -------- \u2705");

    if(poisonItemCount < poisonMission)
        mvwprintw(missionWindow, 7, 0, "  \u26d4 (Poison) -------- (%d)", poisonMission);
    else
        mvwprintw(missionWindow, 7, 0, "  \u26d4 (Poison) -------- \u2705");

    if(boostItemCount < boostMission)
        mvwprintw(missionWindow, 9, 0, "  \u26a1  (Boost) -------- (%d)", boostMission);
    else
        mvwprintw(missionWindow, 9, 0, "  \u26a1  (Boost) -------- \u2705");

    if(gateCount < gateMission)
        mvwprintw(missionWindow, 11, 0, "  \u26e9    (Gate) -------- (%d)", gateMission);
    else
        mvwprintw(missionWindow, 11, 0, "  \u26e9    (Gate) -------- \u2705");

    if(growthItemCount>=growthMission && poisonItemCount>=poisonMission && boostItemCount>=boostMission && gateCount>=gateMission && snake.size()>=3+growthMission) {
        stageClear = true;
    }
}

bool makeSnake() {

    keyPressed = getch();
    if(keyPressed == KEY_RIGHT) {
        direction = 'r';
    } else if(keyPressed == KEY_LEFT) {
        direction = 'l';
    } else if(keyPressed == KEY_DOWN) {
        direction = 'd';
    } else if(keyPressed == KEY_UP) {
        direction = 'u';
    } else if(keyPressed == 'f') {
        direction = 'f';
    }

    if(direction == snakeDirection[0]) {
        snakeHead.second+=2;
    } else if(direction == snakeDirection[1]) {
        snakeHead.first++;
    } else if(direction == snakeDirection[2]) {
        snakeHead.second-=2;
    } else if(direction == snakeDirection[3]) {
        snakeHead.first--;
    }

    if(snakeHead == gate1) { // gate1에 들어갔을 때
        snakeHead = gate2;
        wallSearch();
    } else if(snakeHead == gate2) { // gate2에 들어갔을 때
        snakeHead = gate1;
        wallSearch();
    }  // 게이트에 들어가지 않았을 때

    pair<int, int> tail = snake.front();
    snake.pop_front();
    gameMap[tail.first][tail.second] = 0;

    // 게임종료 조건
    if(gameMap[snakeHead.first][snakeHead.second] == 1)
        return false;
    if(find(snake.begin(), snake.end(), snakeHead) != snake.end())
        return false;
    if(snake.size() < 2)
        return false;
    if(stageClear)
        return false;


    // 아이템 조건
    if(growthItem==snakeHead) {
        growthItemCount++;
        snake.push_front(tail);
        gameMap[tail.first][tail.second] = 3;
        addGrowthItem();
    }
    if(poisonItem==snakeHead) {
        poisonItemCount++;
        gameMap[snake.front().first][snake.front().second] = 0;
        snake.pop_front();
        addPoisonItem();
    }
    if(boostItem==snakeHead) {
        boostItemCount++;
        timeDelay = timeDelay/1.2;
        addBoostItem();
    }


    snake.push_back({snakeHead.first, snakeHead.second});
    gameMap[snakeHead.first][snakeHead.second] = 3;


    return true;
}

void wallSearch() {
    int idx;
    bool flag = false; // 첫번째 while문 실행은 방향을 바꿔주지 않고 실행, 두번째부터 방향을 시계방향으로 돌려
    do {
        copyHead = snakeHead;
        if(flag) direction = snakeDirection[++idx%4];
        if(direction == snakeDirection[0]) {
            copyHead.second+=2;
            idx = 0;
        } else if(direction == snakeDirection[1]) {
            copyHead.first++;
            idx = 1;
        } else if(direction == snakeDirection[2]) {
            copyHead.second-=2;
            idx = 2;
        } else if(direction == snakeDirection[3]) {
            copyHead.first--;
            idx = 3;
        }
        flag = true;
    } while(copyHead.first<0 || copyHead.first>gameWindow_row-1 || copyHead.second<0 || copyHead.second>gameWindow_col-2
        || gameMap[copyHead.first][copyHead.second]==1
        || gameMap[copyHead.first][copyHead.second]==2
        || gameMap[copyHead.first][copyHead.second]==7);
    snakeHead = copyHead;
    gateCount++;
}

void addGrowthItem() {
    if(growthItem.first!=0 || growthItem.second!=0) // 아이템의 초기값은 0,0이므로 예외처리
        gameMap[growthItem.first][growthItem.second] = 0; // 있던 자리 0으로 만들
    do { growthItem = {rand()%(gameWindow_row-2)+1, (rand()%(gameWindow_col/2-2))*2+2};
    } while(gameMap[growthItem.first][growthItem.second] != 0); // 아무것도 없는 자리를 찾아야함
    gameMap[growthItem.first][growthItem.second] = 4;
    time_growth = time(NULL);
}

void addPoisonItem() {
    if(poisonItem.first!=0 || poisonItem.second!=0)
        gameMap[poisonItem.first][poisonItem.second] = 0;
    do { poisonItem = {rand()%(gameWindow_row-2)+1, (rand()%(gameWindow_col/2-2))*2+2};
    } while(gameMap[poisonItem.first][poisonItem.second] != 0); // 아무것도 없는 자리를 찾아야함
    gameMap[poisonItem.first][poisonItem.second] = 5;
    time_poison = time(NULL);
}

void addBoostItem() {
    if(boostItem.first!=0 || boostItem.second!=0)
        gameMap[boostItem.first][boostItem.second] = 0;
    do { boostItem = {rand()%(gameWindow_row-2)+1, (rand()%(gameWindow_col/2-2))*2+2};
    } while(gameMap[boostItem.first][boostItem.second] != 0);  // 아무것도 없는 자리를 찾아야함
    gameMap[boostItem.first][boostItem.second] = 6;
    time_boost = time(NULL);
}
void addGate() {
    gameMap[gate1.first][gate1.second] = 1;
    gameMap[gate2.first][gate2.second] = 1;
    gate1 = wall[rand()%wall.size()];
    do { gate2 = wall[rand()%wall.size()];
    } while(gate1 == gate2);
    // 게이트 생성
    gameMap[gate1.first][gate1.second] = 7;
    gameMap[gate2.first][gate2.second] = 7;

    time_gate = time(NULL);
}

void playGame(int g, int p, int b, int gate) {
    while(direction != 'f') {
        if(!makeSnake()) break;

        if(time(NULL) - time_growth > 7)
            addGrowthItem();
        if(time(NULL) - time_poison > 7)
            addPoisonItem();
        if(time(NULL) - time_boost > 7)
            addBoostItem();
        if(time(NULL) - time_gate > 7 && time(NULL) - playTime > 7)
            addGate();

        drawMap();
        drawScore(g, p, b, gate);
        drawMission(g, p, b, gate);

        wrefresh(gameWindow);
        wrefresh(scoreWindow);
        wrefresh(missionWindow);

        werase(gameWindow);
        werase(scoreWindow);
        werase(missionWindow);

        usleep(timeDelay);
    }
}
