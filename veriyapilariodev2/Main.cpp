#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//Struct yapýsý
struct Ogrenci {
    string ad;
    int id;
    double notu;
};

//Dizide kimlik numarasýna göre öðrenci arama
void ogrenciAra(const vector<Ogrenci>& ogrenciler, int id) {
    for (const auto& ogrenci : ogrenciler) {
        if (ogrenci.id == id) {
            cout << "*********************"<<endl;
            cout << "Ogrenci adi: " << ogrenci.ad << endl;
            cout << "Ogrenci numarasi: " << ogrenci.id << endl;
            cout << "Ortalama: " << ogrenci.notu << endl;
            cout << "---------------------"<<endl;
            return;
        }
    }
    cout << "Ogrenci bulunamadi" << endl;
}
// dizideki notlarýn karþýlaþtýrmasý
bool notuKarsilastir(const Ogrenci& a, const Ogrenci& b) {
    return a.notu > b.notu;
}

//Dizideki her öðrencinin notunu büyükten-küçüðe sýralama
void ogrencileriSiralaNot(const vector<Ogrenci>& ogrenciler) {
    vector<Ogrenci> kopya = ogrenciler;
    sort(kopya.begin(), kopya.end(), notuKarsilastir);
    int sayac = 1;
    string stars = "**********";
    for (const auto& ogrenci : kopya) {
        cout << stars << sayac << stars << endl;
        cout << "Ogrenci adi: " << ogrenci.ad << endl;
        cout << "Ogrenci numarasi: " << ogrenci.id << endl;
        cout << "Ortalama: " << ogrenci.notu << endl;
        cout << "---------------------" << endl;
        sayac++;
    }
}


double notOrtalamasi(const vector<Ogrenci>& ogrenciler,int secim) {
    double toplam = 0.0;
    for (const auto& ogrenci : ogrenciler) {
        toplam += ogrenci.notu;
    }
    return toplam / secim;
}

int main() {
    vector<Ogrenci> ogrenciler;
    int secim;
    int secim2;
    int sayac = 1;
    cout << "Ogrenci Sayisini Giriniz" << endl;
    cin >> secim;
    //diziye Öðrenci ekleme
    for (int i = 0; i < secim; i++)
    {
        Ogrenci ogrenci;
        cout << "Ogrenci Bilgilerini Giriniz "<<sayac<<": "<<endl;

        cout << "Ogrenci adi: ";
        cin >> ogrenci.ad;
        cout << "Ogrenci numarasi: ";
        cin >> ogrenci.id;
        cout << "Ortalama: ";
        cin >> ogrenci.notu;
        ogrenciler.push_back(ogrenci);
        sayac++;
    }

    do {
        cout << endl << "Islem secin:" << endl;
        cout << "1. Ogrencileri numarasina gore ogrenci ara" << endl;
        cout << "2. Ogrencileri ortalamaya gore sirala" << endl;
        cout << "3. Tum ogrencilerin ortalamasini hesaplama" << endl;
        cout << "4. Cikis" << endl;
        cin >> secim2;
        switch (secim2) {
        case 1:
            int id;
            cout << "Aranacak ogrencinin numarasi: ";
            cin >> id;
            ogrenciAra(ogrenciler, id);
            break;
        case 2:
            ogrencileriSiralaNot(ogrenciler);
            break;
        case 3:
            cout << "---------------------" << endl;
            cout<<"Tum ogrencilerin ortalamasi: "<<notOrtalamasi(ogrenciler, secim)<<endl;
            cout << "---------------------" << endl;
            break;
        case 4:
            cout << "Program sonlandirildi" << endl;
            break;
        default:
            cout << "Gecersiz secim" << endl;
        }
    } while (secim2 != 4);
    return 0;
}
