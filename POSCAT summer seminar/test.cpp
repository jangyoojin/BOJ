#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOPAIR 1
#define DOUBLE 2
#define STRAIGHT 3
#define TRIPLE 4

void print_game_status(int round, int user_chips, int com_chips);
void card_shuffle(int* shared_card1, int* shared_card2, int* user_card, int* computer_card);
void print_card_info(int shared_card1, int shared_card2, int user_card, int computer_card);
int is_valid_num(int a, int b, int num);
int user_turn(int user_chips, int* user_betting_chips, int betted_chips, int turn);
int calc_hand(int card, int shared_card1, int shared_card2);
int computer_turn(int user_hand, int com_chips, int* com_betting_chips, int betted_chips, int turn);
int calc_winner(int shared_card1, int shared_card2, int user_card, int computer_card);

int main()
{
   srand(time(NULL));                                                          // 랜덤 시드

   // [1. 프로그램 세팅]

   int round = 1, user_chips = 50, com_chips = 50;                             // round를 1로 초기화, 각 플레이어의 칩의 개수를 각각 50개로 초기화
   int shared_card1, shared_card2, user_card, computer_card;                   // 공유 카드 2장과 각 플레이어의 카드 1장을 나타내는 변수
   int turn = 1, betted_chips = 1;
   int user_betting_chips = 0, com_betting_chips = 0;
   int computer_turn_return = 300, user_turn_return = 300;
   int winner = 0;                                                             // 전 판의 승자 기록

   for (round = 1; round <= 10; round++) {                                     // 최대 게임 횟수 10회


   // [2. 게임 세팅]

      print_game_status(round, user_chips, com_chips);                                 // 2.1 게임 상태 출력
      card_shuffle(&shared_card1, &shared_card2, &user_card, &computer_card);          // 2.2 카드 생성
      print_card_info(shared_card1, shared_card2, user_card, computer_card);           // 2.2 카드 출력


   // [3. 베팅]

      printf("┌────────────────────┐\n");                        // 3. 베팅 초기 화면
      printf("│      Betting       │\n");
      printf("└────────────────────┘\n\n");                        // 베팅 시작 문구 출력

      betted_chips = 1;       // 초기화

      printf("┌────────────┬────────────┐\n");              // 베팅 된 칩의 개수 출력
      printf("│  User: %2d  │   Com: %2d  │\n", betted_chips, betted_chips);
      printf("└────────────┴────────────┘\n\n");

      if (winner == 100) {  // winner ==  100 경우는 user가 승리했다는 뜻이므로 computer부터 베팅 시작
         if (user_chips != 1 && com_chips != 1) {// 두 플레이어 모두 칩을 2개 이상 갖고 있을 경우
            while (1) {

               computer_turn_return = computer_turn(calc_hand(user_card, shared_card1, shared_card2), com_chips, &com_betting_chips, betted_chips, turn);
               if (computer_turn_return == 0) {
                  if (com_chips <= betted_chips) {
                     com_betting_chips = com_chips;
                  }
                  printf("┌────────────┬────────────┐\n");                      // 현재 배팅된 칩의 개수 출력
                  printf("│  User: %2d  │   Com: %2d  │\n", betted_chips, betted_chips + com_betting_chips);
                  printf("└────────────┴────────────┘\n\n");

                  break;
               }
               else if (computer_turn_return == -1) {// Fold일 때 베팅 종료

                  printf("┌────────────┬────────────┐\n");                      // 현재 배팅된 칩의 개수 출력
                  printf("│  User: %2d  │   Com: %2d  │\n", betted_chips, betted_chips - user_betting_chips);
                  printf("└────────────┴────────────┘\n\n");

                  break;
               }

               printf("┌────────────┬────────────┐\n");                      // 현재 배팅된 칩의 개수 출력
               printf("│  User: %2d  │   Com: %2d  │\n", betted_chips, betted_chips + com_betting_chips);
               printf("└────────────┴────────────┘\n\n");

               betted_chips = betted_chips + com_betting_chips;

               user_turn_return = user_turn(user_chips, &user_betting_chips, betted_chips, turn);
               if (user_turn_return == 0) {
                  if (user_chips <= betted_chips) {
                     user_betting_chips = user_chips;
                  }
                  printf("\n┌────────────┬────────────┐\n");                      // 현재 배팅된 칩의 개수 출력
                  printf("│  User: %2d  │   Com: %2d  │\n", betted_chips + user_betting_chips, betted_chips);
                  printf("└────────────┴────────────┘\n\n");

                  break;
               }

               else if (user_turn_return == -1) {
                  printf("\n┌────────────┬────────────┐\n");                      // 현재 배팅된 칩의 개수 출력
                  printf("│  User: %2d  │   Com: %2d  │\n", betted_chips - com_betting_chips, betted_chips);
                  printf("└────────────┴────────────┘\n\n");

                  break;
               }

               printf("\n┌────────────┬────────────┐\n");                      // 현재 배팅된 칩의 개수 출력
               printf("│  User: %2d  │   Com: %2d  │\n", betted_chips + user_betting_chips, betted_chips);
               printf("└────────────┴────────────┘\n\n");

               betted_chips = betted_chips + user_betting_chips;

               turn++;
            }
         }
      }
      else {    // (winner == 200 || winner == 0) 전 판에 computer가 승리 or 첫 판, user부터 베팅 시작
         if (user_chips != 1 && com_chips != 1) { // 두 플레이어 모두 칩을 2개 이상 갖고 있을 경우
            while (1) {

               user_turn_return = user_turn(user_chips, &user_betting_chips, betted_chips, turn);
               if (user_turn_return == 0) {
                  if (user_chips <= betted_chips) {
                     user_betting_chips = user_chips;
                  }
                  printf("\n┌────────────┬────────────┐\n");                      // 현재 배팅된 칩의 개수 출력
                  printf("│  User: %2d  │   Com: %2d  │\n", betted_chips + user_betting_chips, betted_chips);
                  printf("└────────────┴────────────┘\n\n");

                  break;
               }

               else if (user_turn_return == -1) {

                  printf("\n┌────────────┬────────────┐\n");                      // 현재 배팅된 칩의 개수 출력
                  printf("│  User: %2d  │   Com: %2d  │\n", betted_chips - com_betting_chips, betted_chips);
                  printf("└────────────┴────────────┘\n\n");

                  break;
               }

               printf("\n┌────────────┬────────────┐\n");                      // 현재 배팅된 칩의 개수 출력
               printf("│  User: %2d  │   Com: %2d  │\n", betted_chips + user_betting_chips, betted_chips);
               printf("└────────────┴────────────┘\n\n");

               betted_chips = betted_chips + user_betting_chips;

               computer_turn_return = computer_turn(calc_hand(user_card, shared_card1, shared_card2), com_chips, &com_betting_chips, betted_chips, turn);
               if (computer_turn_return == 0) { // Call일 때 베팅 종료
                  if (com_chips <= betted_chips) {
                     com_betting_chips = com_chips;
                  }
                  printf("┌────────────┬────────────┐\n");                      // 현재 배팅된 칩의 개수 출력
                  printf("│  User: %2d  │   Com: %2d  │\n", betted_chips, betted_chips + com_betting_chips);
                  printf("└────────────┴────────────┘\n\n");

                  break;
               }

               else if (computer_turn_return == -1) { // Fold일 때 베팅 종료
                  printf("┌────────────┬────────────┐\n");                      // 현재 배팅된 칩의 개수 출력
                  printf("│  User: %2d  │   Com: %2d  │\n", betted_chips, betted_chips - user_betting_chips);
                  printf("└────────────┴────────────┘\n\n");

                  break;
               }

               printf("┌────────────┬────────────┐\n");                      // 현재 배팅된 칩의 개수 출력
               printf("│  User: %2d  │   Com: %2d  │\n", betted_chips, betted_chips + com_betting_chips);
               printf("└────────────┴────────────┘\n\n");

               betted_chips = betted_chips + com_betting_chips;

               turn++;
            }
         }
      }


      // [4. 베팅 종료(게임 종료)]
         // 4.1 베팅 종료 메시지와 유저의 카드 출력
      printf("────────────────────────────────────────────────────\n\n");
      printf("Betting Finished\n\n");
      printf("┏━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━┓\n");
      printf("┃  Computer  ┃       Shared Cards      ┃     User   ┃\n");
      printf("┣━━━━━━━━━━━━╋━━━━━━━━━━━━┳━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n");
      printf("┃  ┏━━━━━━┓  ┃  ┏━━━━━━┓  ┃  ┏━━━━━━┓  ┃  ┏━━━━━━┓  ┃\n");
      printf("┃  ┃ ♠   ┃  ┃  ┃ ♠   ┃  ┃  ┃ ♠   ┃  ┃  ┃ ♠   ┃  ┃\n");
      printf("┃  ┃      ┃  ┃  ┃      ┃  ┃  ┃      ┃  ┃  ┃      ┃  ┃\n");
      printf("┃  ┃  %2d  ┃  ┃  ┃  %2d  ┃  ┃  ┃  %2d  ┃  ┃  ┃  %2d  ┃  ┃\n", computer_card, shared_card1, shared_card2, user_card);
      printf("┃  ┃      ┃  ┃  ┃      ┃  ┃  ┃      ┃  ┃  ┃      ┃  ┃\n");
      printf("┃  ┃    ♠┃  ┃  ┃    ♠┃  ┃  ┃    ♠┃  ┃  ┃    ♠┃  ┃\n");
      printf("┃  ┗━━━━━━┛  ┃  ┗━━━━━━┛  ┃  ┗━━━━━━┛  ┃  ┗━━━━━━┛  ┃\n");
      printf("┗━━━━━━━━━━━━┻━━━━━━━━━━━━┻━━━━━━━━━━━━┛━━━━━━━━━━━━┛\n\n");

      // 4.2 승리 플레이어 판별 및 출력
      {
         if (computer_turn_return == -1) // computer가 Fold한 경우, user의 승리
            winner = 100;
         else if (user_turn_return == -1) // user가 Fold한 경우, computer의 승리
            winner = 200;
         else if (user_turn_return == 0 || computer_turn_return == 0) // Call을 선택하여 베팅 종료된 경우
            winner = calc_winner(shared_card1, shared_card2, user_card, computer_card);
      }

      if (winner == 100) {
         printf("┌────────────────────┐\n");
         printf("│     User win!      │\n");
         printf("└────────────────────┘\n\n");
      }
      else {
         printf("┌────────────────────┐\n");
         printf("│   Computer win!    │\n");
         printf("└────────────────────┘\n\n");
      }

      // 4.3 플레이어의 칩 개수 업데이트 및 출력

      if (winner == 100) {                // user가 승리한 경우
         user_chips = user_chips + com_betting_chips;
         com_chips = com_chips - com_betting_chips;
      }
      else {                              // computer가 승리한 경우
         user_chips = user_chips - user_betting_chips;
         com_chips = com_chips + user_betting_chips;
      }

      printf("┌──────────────┬──────┐\n");
      printf("│  User        │  %2d  │\n", user_chips);
      printf("│  Computer    │  %2d  │\n", com_chips);
      printf("└──────────────┴──────┘\n");

      // 4.4 게임 진행 여부 입력 및 처리
      int proceedornot;                                   // 게임 계속 진행 여부 변수

      printf("Proceed or Not? [Go: 1, End: -1]: ");       // 게임 계속 진행 여부 입력 요청
      scanf("%d", &proceedornot);

      if (proceedornot == 1) {
         system("cls");
         continue;
      }
      else if (proceedornot == -1)
         break;
   }


   // [5. 프로그램 종료]

      printf("────────────────────────────────────────────────────\n\n");
      printf("Number of Games: %2d\n\n", round);                              // 카드 게임 진행 횟수 출력
      printf("Chips remaining: \n");                                          // 최종 보유 칩 수 출력                                                  
      printf("┌──────────────┬──────┐\n");
      printf("│  User        │  %2d  │\n", user_chips);
      printf("│  Computer    │  %2d  │\n", com_chips);
      printf("└──────────────┴──────┘\n\n\n");

      if (user_chips >= com_chips)                                            // 최종 승리한 플레이어 출력
         printf("User win!\n\n");
      else
         printf("Computer win!\n\n");

      return 0;
}

void print_game_status(int round, int user_chips, int com_chips)                             // 2.1 게임 상태 출력 함수
{
   printf("┌──────────────────────┐\n");                            // 현재 게임이 몇 번째 게임인지 출력
   printf("│   %2d Game Starts!    │\n", round);
   printf("└──────────────────────┘\n\n");

   printf("Chips remaining: \n");                                                           // 각 플레이어의 현재 칩의 개수 출력
   printf("┌──────────────┬──────┐\n");
   printf("│  User        │  %2d  │\n", user_chips);
   printf("│  Computer    │  %2d  │\n", com_chips);
   printf("└──────────────┴──────┘\n\n");

   return;
}

void card_shuffle(int* shared_card1, int* shared_card2, int* user_card, int* computer_card)  // 2.2 카드 생성 함수 
{
   *shared_card1 = rand() % 10 + 1;
   *shared_card2 = rand() % 10 + 1;
   *user_card = rand() % 10 + 1;
   *computer_card = rand() % 10 + 1;
   
   return;
}

void print_card_info(int shared_card1, int shared_card2, int user_card, int computer_card)   // 2.2 카드 출력 함수
{
   printf("┏━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━┓\n");
   printf("┃  Computer  ┃       Shared Cards      ┃     User   ┃\n");
   printf("┣━━━━━━━━━━━━╋━━━━━━━━━━━━┳━━━━━━━━━━━━╋━━━━━━━━━━━━┫\n");
   printf("┃  ┏━━━━━━┓  ┃  ┏━━━━━━┓  ┃  ┏━━━━━━┓  ┃  ┏━━━━━━┓  ┃\n");
   printf("┃  ┃ ♠   ┃  ┃  ┃ ♠   ┃  ┃  ┃ ♠   ┃  ┃  ┃ ♠   ┃  ┃\n");
   printf("┃  ┃      ┃  ┃  ┃      ┃  ┃  ┃      ┃  ┃  ┃      ┃  ┃\n");  
   printf("┃  ┃  %2d  ┃  ┃  ┃  %2d  ┃  ┃  ┃  %2d  ┃  ┃  ┃   ?  ┃  ┃\n", computer_card, shared_card1, shared_card2);
   printf("┃  ┃      ┃  ┃  ┃      ┃  ┃  ┃      ┃  ┃  ┃      ┃  ┃\n");
   printf("┃  ┃    ♠┃  ┃  ┃    ♠┃  ┃  ┃    ♠┃  ┃  ┃    ♠┃  ┃\n");
   printf("┃  ┗━━━━━━┛  ┃  ┗━━━━━━┛  ┃  ┗━━━━━━┛  ┃  ┗━━━━━━┛  ┃\n");
   printf("┗━━━━━━━━━━━━┻━━━━━━━━━━━━┻━━━━━━━━━━━━┛━━━━━━━━━━━━┛\n\n");

   return;
}

int is_valid_num(int a, int b, int num)
{
   if (num >= a && num <= b)
      return 1;
   else
      return 0;
}

int user_turn(int user_chips, int* user_betting_chips, int betted_chips, int turn)       // 3.2 유저의 베팅 턴을 수행하는 함수
{   
   int CRF;                                                                             // Call Raise Fold를 나타내는 변수
   
   while (1) { 
      printf("USER │ [Call: 1 | Raise: 2 | Fold: 3]: ");                       // 유저 베팅을 위한 메시지 출력
      scanf("%d", &CRF);

      if (!(is_valid_num(1, 3, CRF)))                                           // 1, 2, 3 이외의 입력을 한 경우 에러 메시지 출력
         printf("[Invalid input]\n");

      else if (CRF == 1) {                                                      // 사용자가 Call을 선택한 경우
         if (turn == 1)                                                        // 첫 턴에서 Call을 선택한 경우 에러 메시지 출력
            printf("[Invalid input]\n");
         else {                                                                 // 0 반환
            *user_betting_chips = 0;
            return 0;
         }
      }

      else if (CRF == 3) {                                                       // 사용자가 Fold를 선택한 경우
         *user_betting_chips = 0;
         return -1;                                                            // -1 반환
      }

      else                                                                      // 사용자가 Raise를 선택한 경우
         break;                                                                //   반복문 탈출
   }
      printf("[Input number of chips for Raise]: ");                            // 추가로 낼 칩의 개수 입력 받기
      scanf("%d", user_betting_chips);

      return *user_betting_chips;                                               // 추가로 낼 칩의 개수 반환
}

void swap(int* a, int* b) // straight 판별하기 위해 만든 swap 함수
{
   int temp;

   temp = *a;
   *a = *b;
   *b = temp;

   return;
}

int calc_hand(int card, int shared_card1, int shared_card2)
{
   int card1, card2, card3;
   
   card1 = card, card2 = shared_card1, card3 = shared_card2;

   if (card1 > card2)                                                                         // card1, card2, card3 오름차순 재배열
      swap(&card1, &card2);
   if (card1 > card3)
      swap(&card1, &card3);
   if (card2 > card3)
      swap(&card2, &card3);


   if (shared_card1 == shared_card2 && shared_card1 == card)                                 //TRIPLE
      return TRIPLE;
   
   else if (card2 - card1 == 1 && card3 - card2 == 1)                                        //STRAIGHT
      return STRAIGHT;
         
   else if   ((shared_card1 == card || shared_card2 == card) && shared_card1 != shared_card2)      //DOUBLE
      return DOUBLE;

   else                                                                                     //NOPAIR
      return NOPAIR;
}

int computer_turn(int user_hand, int com_chips, int* com_betting_chips, int betted_chips, int turn)     // 3.3 컴퓨터의 베팅 함수
{
   int random;
   random = rand() % 100 + 1;                                                                          // 1부터 100까지의 범위 중 숫자 하나 

   if (user_hand == DOUBLE || user_hand == STRAIGHT || user_hand == TRIPLE)                            // [경우 1] user의 패가 Double or Straight or Triple을 만족할 때 
   {
      if (random <= 70) {                                                                             // [1-1] 70%의 확률로 Fold
         printf("COM │ FOLD\n\n");
         *com_betting_chips = 0;
         return -1;
      }
      else                                                                                            // [1-2] 나머지 30%의 확률로 Call
         if (turn == 1) {                                                                            // 첫 번째 턴일 경우 
            printf("COM │ RAISE, +1\n\n");                                                           // 1개의 칩 Raise

            *com_betting_chips = 1;

            return *com_betting_chips;
         }

         else {                                                                                       // 첫 번째 턴이 아닐 경우
            printf("COM │ CALL\n\n");
            *com_betting_chips = 0;
            return 0;
         }
   }
   else                                                                                                 // [경우 2] user의 패가 Double or Straight or Triple을 만족하지 않을 때 
   {
      if (turn == 1) {                                                                                 // [2-1] 첫 번째 턴일 경우 
         printf("COM │ RAISE, +1\n\n");                                                                // 1개의 칩 Raise
         
         *com_betting_chips = 1;

         return *com_betting_chips;
      }
      
      else if (random <= 50) {                                                                         // [2-2] 50%의 확률로 Call
         printf("COM │ CALL\n\n");
         *com_betting_chips = 0;
         return 0;
      }

      else {                                                                                           // [2-3] 50%의 확률로 Raise
         *com_betting_chips = rand() % 5 + 1;

         if (*com_betting_chips > com_chips) {
            printf("COM │ CALL\n\n");
            return 0;
         }
         
         printf("COM │ RAISE, +%d\n\n", *com_betting_chips);
         
         return *com_betting_chips;
      }
   }
}

int calc_winner(int shared_card1, int shared_card2, int user_card, int computer_card)          // Call을 선택하여 베팅 종료된 경우
{
   int user_hand, computer_hand;                                                              // 두 플레이어의 핸드를 계산하기 위한 변수 선언

   user_hand = calc_hand(user_card, shared_card1, shared_card2);                              // user의 핸드 계산                    
   computer_hand = calc_hand(computer_card, shared_card1, shared_card2);                      // computer의 핸드 계산

   if (user_hand > computer_hand)                                                             // user가 더 높은 핸드를 가질 경우 user의 승리, 100 반환
      return 100;

   else if (computer_hand > user_hand)                                                        // computer가 더 높은 핸드를 가질 경우 computer의 승리, 200 반환
      return 200;

   else {                                                                                     // user와 computer가 같은 핸드를 가질 경우
      if (user_card >= computer_card)                                                        // user의 카드 숫자가 더 높거나 개인 카드의 숫자가 같을 경우 user의 승리, 100 반환
         return 100;
      else                                                                                   // computer의 카드 숫자가 더 높을 경우 computer의 승리, 200 반환
         return 200;
   }
}