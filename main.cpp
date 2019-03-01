#include <bits/stdc++.h>
#include<iostream>
#include<string>

using namespace std;

class wordGame
{
public:
  string word,check[200];
  bool found = false,wordCheck = false;
  int score = 0;
  char lastLetter,firstLetter,checkLetter;
  void inputWord();
  void checkDisc();
  void checkLastLetter();
  void random();
};

void wordGame :: random(){
    int r;
    srand (time(NULL));   
    r = rand() % 26;   
    checkLetter = 'a' + r;     
}

void wordGame :: inputWord(){
  cout << "Enter your next word starting with : "<<lastLetter<<"\n";
  cin >> word;
  firstLetter = word.at(0);
  checkDisc();
}

//checking the last letter with the word
void wordGame :: checkLastLetter(){
  if(firstLetter == checkLetter){
      for(int i=0;i<=score;i++){
        if(check[i] == word){
          wordCheck = true;
          break;
        }
      }
      if(wordCheck == false){
      check[score-1] = word;
      score++;
      checkLetter = lastLetter;
      inputWord();
      }
  }
   // cout<<"game over!\n Your score is : "<<score;
}

void wordGame :: checkDisc(){
  fstream file;
    string str,filename;
    filename = "file.txt";
    file.open(filename.c_str());
    while (file >> str)
    {   found = false;
        if(word == str){
          found = true;
          int len = word.length();
          lastLetter = word.at(len-1);
          checkLastLetter();
          break;
        }
    } 
}

int main(){
  wordGame obj;
  obj.random();
  cout<<"Enter your first word starting with : "<<obj.checkLetter<<"\n";
  cin>>obj.word;
  obj.firstLetter = obj.checkLetter;
  obj.checkDisc();
  if(obj.found == false || obj.wordCheck == true){
    cout<<"Game over!\n"<<"Your score is : "<<obj.score;
  }
  return 0;
}
