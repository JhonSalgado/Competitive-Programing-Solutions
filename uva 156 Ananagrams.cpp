#include<bits/stdc++.h>

using namespace std;

int dif=('A'-'a');

char min(char a){
  return a-dif;
}

int main() {
  char word[20];
  vector<vector<char>> dicc;
  vector<vector<char>> sortDicc;
  while(scanf("%s", word) && word[0]!='#'){
    int len=strlen(word);
    vector<char> v (word, word+len);
    dicc.push_back(v);
    for(int i=0; i<len; i++){
      if(v.at(i)<'a')v.at(i)=min(v.at(i));
    }
    sort(v.begin(), v.end());
    sortDicc.push_back(v);
  }
  vector<char> basurita;
  basurita.push_back('1');
  sortDicc.push_back(basurita);
  dicc.push_back(basurita);
  vector<vector<char>> ans;
  int len=dicc.size();
  for(int i=0; i<len; i++){
    for(int j=0; j<len; j++){
      if(i==j)continue;
      if(sortDicc.at(i)==sortDicc.at(j)){
        break;
      }
      if(j==len-1){
        ans.push_back(dicc.at(i));
      }
    }
  }
  sort(ans.begin(), ans.end());
  for(int i=0; i<ans.size(); i++){
    for(int k=0; k<ans.at(i).size(); k++){
      printf("%c", ans.at(i).at(k));
    }
    printf("\n");
  }
}
