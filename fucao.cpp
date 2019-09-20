#include <iostream>


using namespace std;



//FUNCAO PARA PEGAR O CENTRO DO VETOR DA MEDIANA
int main()
{
    int mascara[9]={5,2,9,4,3,6,7,8,2};
    int mascara2[9]={5,2,9,4,3,6,7,8,2};
    int temp, i , j;
    for(i = 0; i < 9; i++){
        temp = mascara2[i];
        for(j = i-1; j >= 0 && temp < mascara2[j]; j--){
            mascara2[j+1] = mascara2[j];
            cout <<j;
            cout <<"j"; 
            cout<<endl;
        }
        mascara2[j+1] = temp;
        cout <<temp; 
        cout<<endl;
    }

for(int i =0; i<9;i++){
cout <<mascara2[i];

}

cout<< endl;

int auxi=0;

for(int i=1;i<9;i++){
    for(j=0;j<8;j++){
        if(mascara[j]>mascara[j+1]){
        auxi = mascara[j];
        mascara[j] = mascara[j+1];
        mascara[j+1] = auxi;
        }
        
    } 
}


for(int i =0; i<9;i++){
cout <<mascara[i];

}

    return 0;
}
