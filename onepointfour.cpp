#include <stdio.h>
struct DIEM
{
    int hoanhDo;
    int tungDo;
};
void main()
{
    // khoi tao cac bien gia tri
    int a = 1;
    DIEM d;
    d.hoanhDo = 1;
    d.tungDo = 2;
    // khai bao bien con tro va tro den vung nho cua cac bien gia tri da co
    int *pa = &a;
    int *pb = pa;
    DIEM *pd = &d;
    // xac dinh dia chi o nho: toan tu &
    printf("Dia chi o nho: %d \n", &a);
    // truy xuat gia tri o nho tu bien con tro: toan tu *
    printf("Gia tri a: %d \n", *pa);
    // truy xuat thanh phan trong cau truc
    printf("Diem D: (%d,%d)\n", d.hoanhDo, d.tungDo);     // doi voi bien gia tri: .
    printf("Diem D: (%d,%d)\n", pd->hoanhDo, pd->tungDo); // doi voi bien con tro: ->
    delete pd;
}