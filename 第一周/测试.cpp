#include<iostream>
#include<array>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<stack>
#include"qgforwardlist.h"
#include"qglist.h"
using namespace std;
void fx(QGForwardList::ElemType& e) {
    e = e + 3;
}
void fy(QGList::ElemType& e) {
    e = e + 3;
}
int main() {
    char ch;
    QGForwardList L;
    cout << "b:���ص�һ������" << endl;
    cout << "c:�������һ������" << endl;
    cout << "d:�������һ��Ԫ��ǰ���Ԫ��" << endl;
    cout << "e:ɾ�������һ��Ԫ��" << endl;
    cout << "f:���������һ��Ԫ�غ����Ԫ��" << endl;
    cout << "g:ɾ���������һ��Ԫ��" << endl;
    cout << "h:������ĵ�index + 1��Ԫ��ǰ����Ԫ��e" << endl;
    cout << "i:ɾ������λ��Ԫ��" << endl;
    cout << "j:�������" << endl;
    cout << "k:����Ԫ���Ƿ����" << endl;
    cout << "l:����������Ԫ�ص�����" << endl;
    cout << "n:��������, ��ÿ��Ԫ�ص���visitָ��ĺ���" << endl;
    cout << "m:��ת����1234��ת����4321" << endl;
    cout << "p:ż�ڵ㷴ת��1234��ת����2143" << endl;
    cout << "q:�����м�ڵ�" << endl;
    cout << "T:�˳�" << endl;
    cin >> ch;
    while (ch) {
        system("cls");
        if (ch == 'T' || ch == 't')return 0;
        cout << "b:���ص�һ������" << endl;
        cout << "c:�������һ������" << endl;
        cout << "d:�������һ��Ԫ��ǰ���Ԫ��" << endl;
        cout << "e:ɾ�������һ��Ԫ��" << endl;
        cout << "f:���������һ��Ԫ�غ����Ԫ��" << endl;
        cout << "g:ɾ���������һ��Ԫ��" << endl;
        cout << "h:������ĵ�index + 1��Ԫ��ǰ����Ԫ��e" << endl;
        cout << "i:ɾ������λ��Ԫ��" << endl;
        cout << "j:�������" << endl;
        cout << "k:����Ԫ���Ƿ����" << endl;
        cout << "l:����������Ԫ�ص�����" << endl;
        cout << "n:��������, ��ÿ��Ԫ�ص���visitָ��ĺ���" << endl;
        cout << "m:��ת����1234��ת����4321" << endl;
        cout << "p:ż�ڵ㷴ת��1234��ת����2143" << endl;
        cout << "q:�����м�ڵ�" << endl;
        cout << "T:�˳�" << endl;
        switch (ch) {
        case'b':cout << L.front(); cout << endl << "��T����"; cin >> ch; break;
        case'c':cout << L.back(); cout << endl << "��T����"; cin >> ch; break;
        case'd':QGForwardList::ElemType a; cout << "����Ҫ�ӵ���"; cin >> a; L.push_front(a);
            cout << endl << "��T����"; cin >> ch; break;
        case'e':L.pop_front(); cout << endl << "��T����"; cin >> ch; break;
        case'f':QGForwardList::ElemType b; cout << "����Ҫ�ӵ���"; cin >> b; L.push_back(b);
            cout << endl << "��T����"; cin >> ch; break;
        case'g':L.pop_back(); cout << endl << "��T����"; cin >> ch; break;
        case 'h':unsigned int c; cout << endl << "����index" << endl << "��������λ��e"; cin >> c;
            QGForwardList::ElemType d; cout << "����������d"<<endl; cin >> d;
            L.insert(c, d); cout << endl << "��T����"; cin >> ch; break;
        case'i': unsigned int e; cout << "����ɾ��λ��e" << endl;
            cin >> e; L.erase(e); cout << endl << "��0����"; cin >> ch; break;
        case'j':L.clear(); cout << endl << "��T����"; cin >> ch; break;
        case'k':QGForwardList::ElemType f; cout << endl << "������Ҫ���ҵ���"<<endl; cin >> f; L.contain(f); cout << endl << "��T����"; cin >> ch; break;
        case'l':L.size(); cout << endl << "��T����"; cin >> ch; break;
        case'n':cout << "��֪�������ô��д�˸�ÿ���3��";
            L.traverse(fx); cout << endl << "��T����"; cin >> ch; break;
        case'm':L.reverse(); cout << endl << "��T����"; cin >> ch; break;
        case'p':L.reverseEven(); cout << endl << "��T����"; cin >> ch; break;
        case'q': ; cout << endl << "�м���Ϊ" <<L.middleElem();
            cout << endl << "��T����"; cin >> ch; break;
        
        default:cin >> ch; break;
        }
    }
    return 0;
}