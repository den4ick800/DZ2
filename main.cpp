#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int main(int argc, const char* argv[]) {
    if (argc != 3) {
        cerr << "Error: Use three parameters\n";
        return 5;
    }
    const string mode(argv[1]); // Режим работы
    const string file_name(argv[2]); // Имя файла
     if (mode == "encryption") {
    // Режим шифрование
    char str;
    int password;
    cout<<"Enter text ( length - 1 byte)\n";
    //поскольку у нас длина текста 1 символ,значит можем сразу положить символ в переменную char
    cin>>str;
cout<<"Write password\n";
    cout<<"Password-";
    cin>>password;
    srand(password);
    int h=static_cast<int>(str); //перевод символа в число
    h=h^rand();
    h>>1;
    int last=h%2;//сохраняем последнюю цифру, чтобы оно не пропала
    h>>1;
    int last_1=h%2;//сохраняем предпоследнюю цифру, чтобы она не пропала
    //добавляем эти цифры слева
    h=h+(last*pow(2,7))+(last_1*pow(2,8));
         ofstream file;
         //помещаем значение в файл
         file.open(file_name, ios::binary);
         file << h;
         file.close();
}
else if (mode == "decryption") {
// Режим расшифрования
int password_2;
cout<<"Write password"<<endl<<"Password-";
cin>>password_2;
int n;
//Достаем зашифрованные данные из файла
ifstream file;
file.open(file_name, ios::binary);
file>>n;
//Сохраняем две первые цифры, чтобы они не пропали
int first=n/pow(2,8);
n<<1;
int first_1=n/pow(2,8);
n<<1;
//добавляем эти цифры с правой стороны
n=n+first_1+(first*2);
//переводим число в символ
char str_1=n;
cout<<str_1;
}
return 0; }
