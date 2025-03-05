#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    set <string> voc; //слова с ударениями
    set <string> voc1; //слове заглавными буквами
    int n, l, i, k, ans = 0, numaccents = 0;
    string a, st, check;
    bool failed = false;
    cin >> n;
    //Заполняем словарь
    for (i = 0; i < n; i++){
        cin >> a;
        voc.insert(a);
        for (int j = 0; j < a.length(); j++){
            st += toupper(a[j]);
        }
        voc1.insert(st);
        st = "";
    }
    i = 0;
    //Обрабатываем слова Васи
    while (cin >> a){
            if (voc.find(a) == voc.end()){
                //Пробегаем по слову
                for (k = 0; k < a.length(); k++)
                    if (a[k] >= 'A' && a[k] <= 'Z'){
                        numaccents++;
                    }//Дошли до конца
                check = "";
                for (int j = 0; j < a.length(); j++){
                    check += toupper(a[j]);
                }
                if (numaccents != 1)
                    failed = true;
                else if ((voc1.find(check) != voc1.end()))
                    failed = true;
                if (failed)
                    ans++;
                failed = false; numaccents = 0;
            }
        }
    cout << ans;
    return 0;
} 