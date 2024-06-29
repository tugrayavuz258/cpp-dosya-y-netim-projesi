
/****************************************************************************
**					SAKARYA ÜNİVERSİTESİ
**				BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				    BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				   PROGRAMLAMAYA GIRIS DERSI
**                 PROJE-1 (2022-2023 GÜZ DONEMI)
**
**				PROJE NUMARASI : PROJE-1
**				ÖĞRENCİ ADI-SOYADI : Tuğra YAVUZ
**				ÖĞRENCİ NUMARASI:B221210064
**               DERSİN ALINDIĞI GRUP: 1. ogretim A-grubu
****************************************************************************/



#include <fstream>
#include <iostream>
#include <string>       //kutuphanelerimiz
#include <iomanip>

using namespace std;

class urun //urun sinifi
{
public:
    string urunadi;
    int uretildigigun; //sinif degiskenlerimiz
    int uretildigiay;
    int uretildigiyil;
    int sontuketimgun;
    int sontuketimay;
    int sontuketimyil;
    float yuzgramdakalori;
    float stokadeti;
    float birimmiktargelisfiyati;
    float birimmiktarsatisfiyati;
    urun() :urunadi(""), uretildigigun(0), uretildigiay(0), uretildigiyil(0), sontuketimgun(0), sontuketimay(0), sontuketimyil(0), yuzgramdakalori(0.0), stokadeti(0), birimmiktargelisfiyati(0), birimmiktarsatisfiyati(0)
    {  //parametresiz kurucu fonksiyon

    }
    urun(string urunadi, int uretildigigun, int uretildigiay, int uretildigiyil, int sontuketimgun, int sontuketimay, int sontuketimyil, float yuzgramdakalori, float stokadeti, float birimmiktargelisfiyati, float birimmiktarsatisfiyati)
    {
        this->urunadi = urunadi;
        this->uretildigigun = uretildigigun;
        this->uretildigiay = uretildigiay;
        this->uretildigiyil = uretildigiyil;  //parametreli kurucu fonksiyon
        this->sontuketimgun = sontuketimgun;
        this->sontuketimay = sontuketimay;
        this->sontuketimyil = sontuketimyil;
        this->yuzgramdakalori = yuzgramdakalori;
        this->stokadeti = stokadeti;
        this->birimmiktargelisfiyati = birimmiktargelisfiyati;
        this->birimmiktarsatisfiyati = birimmiktarsatisfiyati;

    }
    //depo menu fonksiyonlari
    void depotxtraporalma() {  //depodan rapor alma fonksiyonu
        cout << setw(4) << "urun adlari " << setw(4) << "uretildikleri tarih " << setw(4) << " son tuketim tarihleri " << setw(4) << " yuz gramda kalori degerleri " << setw(4) << " stok adetleri " << setw(4) << " birim miktar gelis fiyati " << setw(4) << " birim miktar satis fiyati \n\n\n";
        ifstream deporaporoku("depo.txt");
        while (deporaporoku >> urunadi >> uretildigigun >> uretildigiay >> uretildigiyil >> sontuketimgun >> sontuketimay >> sontuketimyil >> yuzgramdakalori >> stokadeti >> birimmiktargelisfiyati >> birimmiktarsatisfiyati) {
            cout << setw(4) << urunadi << setw(4) << uretildigigun << "." << uretildigiay << "." << uretildigiyil << setw(4) << sontuketimgun << "." <<         //tek tek depodaki urunlerin bilgilerini okuyan dongu
                sontuketimay << "." << sontuketimyil;
            cout << setw(4) << yuzgramdakalori << setw(4) << stokadeti << setw(4) << birimmiktargelisfiyati << setw(4) << birimmiktarsatisfiyati << endl;
        }
        deporaporoku.close();
    }
    void depotxtkayitsilme() { //depodan urun silmeye yarayan fonksiyon
        string silinmekistenenurunismi;
        cout << "\n\nlutfen depodan silmek isteginiz urunun ismini giriniz (kucuk harflerle ve birlesik)\n\n";
        cin >> silinmekistenenurunismi;
        ifstream depotxtoku("depo.txt");
        ofstream depotxtyaz("depokayitsilme.txt");
        while (depotxtoku >> urunadi >> uretildigigun >> uretildigiay >> uretildigiyil >> sontuketimgun >> sontuketimay >> sontuketimyil >> yuzgramdakalori >> stokadeti >> birimmiktargelisfiyati >> birimmiktarsatisfiyati) {
            //depodaki urun verilerini okuyan while dongusu
            if (silinmekistenenurunismi == urunadi) { //eger silmek istedgimiz urunle okunan isim ayniysa istenen urun silinmis (guncel) dosyaya aktarilmasin diye kontrol saglayan if
                cout << "\nsilinmek istenen urunun adi: " << urunadi << endl;
                cout << "\nurunun uretildigi tarih: " << uretildigigun << "." << uretildigiay << "." << uretildigiyil << endl;
                cout << "\nurunun son tuketim tarihi: " << sontuketimgun << "." << sontuketimay << "." << sontuketimyil << endl;
                cout << "\nurunun yuz gramda kalorisi: " << yuzgramdakalori << endl;
                cout << "\nurunun kalan stogu: " << stokadeti << endl;
                cout << "\nurunun birim miktar gelis fiyati: " << birimmiktargelisfiyati << endl;
                cout << "\nurunun birim miktar satis fiyati: " << birimmiktarsatisfiyati << endl;
            }

            else { //eger silinmek istenenle ismi ayni degilse guncel dosyaya yaziyor

                depotxtyaz << " " << urunadi << " " << uretildigigun << " " << uretildigiay << " " << uretildigiyil << " " << sontuketimgun << " " << sontuketimay << " ";
                depotxtyaz << sontuketimyil << " " << yuzgramdakalori << " " << stokadeti << " " << birimmiktargelisfiyati << " " << birimmiktarsatisfiyati << " " << endl;

            }


        }

        depotxtyaz.close();
        depotxtoku.close();
        remove("depo.txt");
        rename("depokayitsilme.txt", "depo.txt");

    }

    void depotxtkayitekleme() { //depoya urun eklememizi saglayan fonksiyon 
        char kayiteklemedevamedecekmi;
        ofstream depotxtyaz("depokayitekle.txt");
        ifstream depotxtoku("depo.txt");
        while (depotxtoku >> urunadi >> uretildigigun >> uretildigiay >> uretildigiyil >> sontuketimgun >> sontuketimay >> sontuketimyil >> yuzgramdakalori >> stokadeti >> birimmiktargelisfiyati >> birimmiktarsatisfiyati) {
            depotxtyaz << " " << urunadi << " " << uretildigigun << " " << uretildigiay << " " << uretildigiyil << " " << sontuketimgun << " " << sontuketimay; //depodaki veriler okunuyor
            depotxtyaz << " " << sontuketimyil << " " << yuzgramdakalori << " " << stokadeti << " " << birimmiktargelisfiyati << " " << birimmiktarsatisfiyati << " " << endl;
        }

        do {
            cout << "\nurun adini giriniz" << endl; cin >> urunadi;
            cout << "\nurun uretim gununu giriniz (sadece gun)" << endl; cin >> uretildigigun;
            cout << "\nurun uretim ayini giriniz" << endl; cin >> uretildigiay;
            cout << "\nurun uretim yilini giriniz" << endl; cin >> uretildigiyil;                                       //yeni bilgiler aliniyor
            cout << "\nurunun son tuketin gununu giriniz (sadece gun)" << endl; cin >> sontuketimgun;
            cout << "\nurunun son tuketim ayini giriniz" << endl; cin >> sontuketimay;
            cout << "\nurunun son tuketim yilini giriniz" << endl; cin >> sontuketimyil;
            cout << "\nurunun yuz gramda kalorisini giriniz" << endl; cin >> yuzgramdakalori;
            cout << "\nurunun stok bilgisini giriniz" << endl; cin >> stokadeti;
            cout << "\nurunun birim miktar gelis fiyatini yaziniz" << endl; cin >> birimmiktargelisfiyati;
            cout << "\nurunun birim miktar satis fiyatini giriniz" << endl; cin >> birimmiktarsatisfiyati;
            depotxtyaz << " " << urunadi << " " << uretildigigun << " " << uretildigiay << " " << uretildigiyil << " " << sontuketimgun << " " << sontuketimay << " "; //eklenen veriler dosyaya yaziliyor
            depotxtyaz << sontuketimyil << " " << yuzgramdakalori << " " << stokadeti << " " << birimmiktargelisfiyati << " " << birimmiktarsatisfiyati << " " << endl;
            cout << "\n\n yeni kayit eklenecek mi? eger bir kayit daha eklemek istiyorsaniz e harfini tuslayiniz";
            cin >> kayiteklemedevamedecekmi; //daha fazla kayit eklenmek isteniyor mu diye kontrol edn do while dongusu
        } while (kayiteklemedevamedecekmi == 'e');
        depotxtyaz.close();
        depotxtoku.close();
        remove("depo.txt");
        rename("depokayitekle.txt", "depo.txt");
        cout << "\n\n\n kayitlariniz basariyla eklenmistir\n\n\n";
    }
    void depobilgileriguncellemefonksiyonu() { //depodaki urunlerin verilerini duzeltmek amaciyla kullanilan fonksiyon
        ifstream depotxtoku("depo.txt");
        ofstream depotxtyaz("depoguncelleme.txt");
        string duzeltilmekistenenurunismi;
        cout << "\nbilgilerini guncellemek istediginiz urunun ismini giriniz(kucuk harflerle ve birlesik)\n"; cin >> duzeltilmekistenenurunismi;
        while (depotxtoku >> urunadi >> uretildigigun >> uretildigiay >> uretildigiyil >> sontuketimgun >> sontuketimay >> sontuketimyil >> yuzgramdakalori >> stokadeti >> birimmiktargelisfiyati >> birimmiktarsatisfiyati) {
            //depodan veriler okunuyor
            if (duzeltilmekistenenurunismi == urunadi)
            { //eger urunun ismi duzeltemk istedigimizz urunle ayniysa bu kod blogu calisiyor ve verileri guncelleyip yeni guncel dosyamiza yaziyor
                cout << "\nurunun adi: " << urunadi << endl;
                cout << "\nurunun uretildigi tarih: " << uretildigigun << "." << uretildigiay << "." << uretildigiyil << endl;
                cout << "\nurunun son tuketim tarihi: " << sontuketimgun << "." << sontuketimay << "." << sontuketimyil << endl;
                cout << "\nurunun yuz gramda kalorisi: " << yuzgramdakalori << endl;
                cout << "\nurunun kalan stogu: " << stokadeti << endl;
                cout << "\nurunun birim miktar gelis fiyati: " << birimmiktargelisfiyati << endl;
                cout << "\nurunun birim miktar satis fiyati: " << birimmiktarsatisfiyati << endl;
                cout << "\n\n guncel verileri giriniz\n\n";                                                                                 //yeni bilgiler aliniyor
                cout << "\nurun adini giriniz" << endl; cin >> urunadi;
                cout << "\nurun uretim gununu giriniz (sadece gun)" << endl; cin >> uretildigigun;
                cout << "\nurun uretim ayini giriniz" << endl; cin >> uretildigiay;
                cout << "\nurun uretim yilini giriniz" << endl; cin >> uretildigiyil;
                cout << "\nurunun son tuketin gununu giriniz (sadece gun)" << endl; cin >> sontuketimgun;
                cout << "\nurunun son tuketim ayini giriniz" << endl; cin >> sontuketimay;
                cout << "\nurunun son tuketim yilini giriniz" << endl; cin >> sontuketimyil;
                cout << "\nurunun yuz gramda kalorisini giriniz" << endl; cin >> yuzgramdakalori;
                cout << "\nurunun stok bilgisini giriniz" << endl; cin >> stokadeti;
                cout << "\nurunun birim miktar gelis fiyatini yaziniz" << endl; cin >> birimmiktargelisfiyati;
                cout << "\nurunun birim miktar satis fiyatini giriniz" << endl; cin >> birimmiktarsatisfiyati;
                depotxtyaz << " " << urunadi << " " << uretildigigun << " " << uretildigiay << " " << uretildigiyil << " " << sontuketimgun << " " << sontuketimay << " ";
                depotxtyaz << sontuketimyil << " " << yuzgramdakalori << " " << stokadeti << " " << birimmiktargelisfiyati << " " << birimmiktarsatisfiyati << " " << endl;
                //guncel veriler yaziliyor
            }
            else { //guncellenmyecek urunler aynen guncel dosyaya aktariliyor
                depotxtyaz << " " << urunadi << " " << uretildigigun << " " << uretildigiay << " " << uretildigiyil << " " << sontuketimgun << " " << sontuketimay;
                depotxtyaz << " " << sontuketimyil << " " << yuzgramdakalori << " " << stokadeti << " " << birimmiktargelisfiyati << " " << birimmiktarsatisfiyati << " " << endl;
            }

        }
        depotxtyaz.close();
        depotxtoku.close();
        remove("depo.txt");
        rename("depoguncelleme.txt", "depo.txt");
        cout << "\n\n guncelleme isleminiz basariyla gerceklesti \n\n";
    }
};
class yemekcesit : public urun {  //urun classindan turetilmis yemekcesit sinifi burada yemekler hakkinda bilgiler tutuluyor
public:
    float yemeklericinyuzgramdakolari; //degiskenlerimiz
    float toplammaliyetifdegeri;
    float toplammaliyetsondeger;
    float toplammaliyetilkdeger;
    float toplammaliyetkontroldegeri;
    float yemekicinihtiyacduyulanmalzemeraporundagosterilecekmaliyet;
    float toplamparagirisilkdeger;
    float toplamparagiriskontroldegeri;
    float kullanilacakmiktar;
    int eldekiyemeksayisi;
    string kullanilacakmalzeme;
    string eldekalanyemekadlari;
    int eldekalanyemeksayisi = 0;
    string yemekadi;
    string malzemelerdekullanmakicinyemekadi;
    string eldekiyemektxticinyemekadi;
    int eldekiyemektxticineldekiyemeksayisi;


    //yemek cesiti menu islemleri
    void yemekcesittxtkayitekleme() { //yemekcesit dosyamiza yeni yemek ve onun tarifini eklemeye yarayan kod blogu
        char yemekcesiticinkontrol;
        char malzemedosyasiicinkontrol;
        ifstream yemekcesittxtoku("yemekcesit.txt");
        ofstream yemekcesittxtyaz("yemekcesityedek.txt");
        while (yemekcesittxtoku >> yemekadi) {// yemek isimleri okunuyor
            yemekcesittxtyaz << " " << yemekadi << endl;
        }
        do {//kullanici baska yemek eklemek istiyor mu bunun kontrolunu saglayan do while
            cout << "\n eklemek istediginiz yemegin adini giriniz" << endl; cin >> yemekadi;
            ifstream malzemetxtoku("malzeme.txt");
            ofstream malzemetxtyaz("malzemeyedek.txt");
            while (malzemetxtoku >> malzemelerdekullanmakicinyemekadi >> kullanilacakmiktar >> kullanilacakmalzeme) { //yemek malzemelerini okuyan while
                malzemetxtyaz << " " << malzemelerdekullanmakicinyemekadi << " " << kullanilacakmiktar << " " << kullanilacakmalzeme << endl;
            }
            do { // yemege baska malzeme eklenmek isteniyor mu kontrol eden do while
                malzemelerdekullanmakicinyemekadi = yemekadi;
                cout << "\n lutfen" << malzemelerdekullanmakicinyemekadi << "icin";
                short malzemelistesisayaci = 1;
                cout << "\n kutfen ismini girdiginiz yemegi yapmak icin gereken " << malzemelistesisayaci << ". malzemenin kullanim miktarini giriniz"; cin >> kullanilacakmiktar;
                cout << "\n lutfen ismini girdiginiz yemegi yapmak icin gereken " << malzemelistesisayaci << ". " << "malzemeyi giriniz" << endl; cin >> kullanilacakmalzeme;
                malzemetxtyaz << " " << malzemelerdekullanmakicinyemekadi << " " << kullanilacakmiktar << " " << kullanilacakmalzeme << endl;
                cout << "\n yemeginizin yapiminda kullanmak uzere baska malzeme kullanmak istiyor musunuz istiyorsaniz e istmiyorsaniz h tuslayin" << endl;
                cin >> malzemedosyasiicinkontrol;
                malzemelistesisayaci++;
            } while (malzemedosyasiicinkontrol == 'e');
            malzemetxtoku.close();
            malzemetxtyaz.close();
            remove("malzeme.txt");
            rename("malzemeyedek.txt", "malzeme.txt");
            yemekcesittxtyaz << " " << yemekadi << endl;
            cout << "\n baska yemek icin kayit yapmak istiyor musunuz istiyorsaniz e istemiyorsaniz h tuslayiniz" << endl;
            cin >> yemekcesiticinkontrol;
        } while (yemekcesiticinkontrol == 'e');
        yemekcesittxtoku.close();
        yemekcesittxtyaz.close();
        remove("yemekcesit.txt");
        rename("yemekcesityedek.txt", "yemekcesit.txt");

    }
    void yemekcesittxticinkayitsilme() { //yemek cesıtlerınden ve tarıflerden yemek sılmeye yarayan fonsksıyon
        string silinmekistenenyemekismi;
        cout << "\n\n lutfen kaydini silmek istediginiz yemegin ismini giriniz (kucuk harflerle ve bosluk yerine _ kullanarak)\n\n";
        cin >> silinmekistenenyemekismi;
        ifstream yemekcesittxtoku("yemekcesit.txt");
        ifstream malzemetxtoku("malzeme.txt");
        ofstream yemekcesittxtyaz("yemekcesityedek.txt");
        ofstream malzemetxtyaz("malzemeyedek.txt");
        while (yemekcesittxtoku >> yemekadi) { //yemekadları okunuyor

            if (silinmekistenenyemekismi == yemekadi) //sılınmek ıstenen yemek ısmı okunan yemekle aynıysa guncel dosyaya yazımı engellenıyor (bunu kontrol eden ıf)
            {
                cout << "\n silinmek istenen yemek ismi: " << yemekadi << endl;
            }
            else { //silinmek istenenle ayni degilse guncel dosyaya yaziliyor
                yemekcesittxtyaz << " " << yemekadi << endl;
            }
        }
        while (malzemetxtoku >> malzemelerdekullanmakicinyemekadi >> kullanilacakmiktar >> kullanilacakmalzeme) { //malzeme dosyasindan tarifler okunuyor
            if (malzemelerdekullanmakicinyemekadi == silinmekistenenyemekismi) {
                //silinmek istenen yemek ismiyle okunan yemek ismi ayniysa guncel dosyayaya yazmayi engelleyen if 
            }
            else {
                //silinmek istenen yemek ismiyle okunan yemek ismi ayni degilse guncel dosyaya yaziliyor
                malzemetxtyaz << " " << malzemelerdekullanmakicinyemekadi << " " << kullanilacakmiktar << " " << kullanilacakmalzeme << endl;
            }
        }
        yemekcesittxtoku.close();
        yemekcesittxtyaz.close();
        malzemetxtoku.close();
        malzemetxtyaz.close();
        remove("yemekcesit.txt");
        remove("malzeme.txt");
        rename("yemekcesityedek.txt", "yemekcesit.txt");
        rename("malzemeyedek.txt", "malzeme.txt");
    }
    void yemekcesiticinraporalma() { //yemek tariflerinden rapor almaya yarayan kod
        ifstream malzemetxtoku("malzeme.txt");
        cout << "\n\n\n yemek, yemeklerde kullanilacak malzemeler ve miktarlari icin raorunuz: \n\n\n";
        while (malzemetxtoku >> malzemelerdekullanmakicinyemekadi >> kullanilacakmiktar >> kullanilacakmalzeme) { // malzeme yani tarif dosyasindan veriler okunuyor

            cout << malzemelerdekullanmakicinyemekadi << " icin " << kullanilacakmiktar << "kadar birimde (kg veya l) " << kullanilacakmalzeme << endl;
        }
        malzemetxtoku.close();
    }

    void yemekcesiticinguncelleme() { //yemekcesit dosyasinda yemek verilerini guncellemeye yarayan kod (malzemelerdeki verileri de guncelliyor)
        string yemekadindanmalzemeyegecisicinstring;
        string guncellenmekistenenyemekismi;
        cout << "\n\n lutfen kaydini degistirmek istediginiz yemegin ismini giriniz (kucuk harflerle ve bosluk yerine _ kullanarak)\n\n";
        cin >> guncellenmekistenenyemekismi;
        ifstream yemekcesittxtoku("yemekcesit.txt");
        ofstream yemekcesittxtyaz("yemekcesityedek.txt");
        while (yemekcesittxtoku >> yemekadi) { //yemek isimleri okunuyor

            if (guncellenmekistenenyemekismi == yemekadi) { //guncellenmek istenen yemek ismi okunan yemek adiyla ayniysa calisip yemegin ismini guncelleyen kod blogu
                cout << "\n yemegin yeni adini giriniz" << endl; cin >> yemekadi;
                yemekadindanmalzemeyegecisicinstring = yemekadi;
                yemekcesittxtyaz << " " << yemekadi << endl;
            }
            else { //yemek ismi degismek istenmiyorsa aynen guncel dosyaya yaziliyor
                yemekcesittxtyaz << " " << yemekadi << endl;
            }
        }
        yemekcesittxtoku.close();
        yemekcesittxtyaz.close();
        ifstream malzemetxtoku("malzeme.txt");
        ofstream malzemetxtyaz("malzemeyedek.txt");
        while (malzemetxtoku >> malzemelerdekullanmakicinyemekadi >> kullanilacakmiktar >> kullanilacakmalzeme)
        {// malzeme dosyasindan tarifler okunuyor
            if (guncellenmekistenenyemekismi == malzemelerdekullanmakicinyemekadi) { // guncellenmek istenen yemek ismiyle okunan isim ayniysa yemegin ismini ve malzemeleri guncellemeye yarayn if
                cout << " lutfen " << yemekadindanmalzemeyegecisicinstring << " isimli yemeginizde kullanilacak " << kullanilacakmalzeme;
                cout << " isimli urunu degistirmek istiyorsaniz yeni urun adini girin degistirmek istemiyorsaniz aynini girin" << endl;
                cin >> kullanilacakmalzeme;
                cout << " lutfen " << yemekadindanmalzemeyegecisicinstring << " isimli yemeginizde kullanilacak olan " << kullanilacakmalzeme;
                cout << " isimli urunden kullanmak istediginiz miktari kg veya l cinsinden yazin " << endl;
                cin >> kullanilacakmiktar;
                malzemetxtyaz << " " << yemekadindanmalzemeyegecisicinstring << " " << kullanilacakmiktar << " " << kullanilacakmalzeme << " " << endl;
            }
            else { //eger okunan yemek ismi guncellenmek istenenle ayni degilse aynen guncel dosyaya aktariliyor
                malzemetxtyaz << " " << malzemelerdekullanmakicinyemekadi << " " << kullanilacakmiktar << " " << kullanilacakmalzeme << " " << endl;
            }
        }
        malzemetxtoku.close();
        malzemetxtyaz.close();
        remove("yemekcesit.txt");
        remove("malzeme.txt");
        rename("yemekcesityedek.txt", "yemekcesit.txt");
        rename("malzemeyedek.txt", "malzeme.txt");

    }
    void yemekuretimfonksiyon() { //malzemelerden yemek uretimi yapip stoklari eritmemize yarayan fonksiyon
        ifstream yemekcesittxtoku("yemekcesit.txt");
        ofstream eldekiyemektxtyaz("eldekiyemek.txt");
        int uretilmekistenenyemeksayisi;
        float ificinstokadetikontrolu;
        int eksikciktimi = 0;
        int elseifcalistimi = 0;
        string depodayemekicintekrarguncellemeleriengellenemkicinkullanilacakstringdegiskeni = "asd";
        while (yemekcesittxtoku >> yemekadi) { //yemek adlari okunuyor 
            cout << yemekadi << " adli yemekten kac adet uretmek istiyorsunuz?\n"; cin >> uretilmekistenenyemeksayisi;
            ifstream malzemetxtoku("malzeme.txt");
            while (malzemetxtoku >> malzemelerdekullanmakicinyemekadi >> kullanilacakmiktar >> kullanilacakmalzeme) { //malzemelerden yemek adlari okunuyor

                if (malzemelerdekullanmakicinyemekadi == yemekadi) { //okunan yemek adiyla malzemelerden okunan yemek adi ayni mi kontrol eden if
                    {
                        ifstream depotxtoku("depo.txt");
                        ofstream depotxteksikmalzemeciktiyaz("depoyedekeksikkaynak.txt");
                        while (depotxtoku >> urunadi >> uretildigigun >> uretildigiay >> uretildigiyil >> sontuketimgun >> sontuketimay >> sontuketimyil >> yuzgramdakalori >> stokadeti >> birimmiktargelisfiyati >> birimmiktarsatisfiyati)
                        {//depo verileri okunup koruma dosyasina isleniyor
                            depotxteksikmalzemeciktiyaz << " " << urunadi << " " << uretildigigun << " " << uretildigiay << " " << uretildigiyil << " " << sontuketimgun << " " << sontuketimay;
                            depotxteksikmalzemeciktiyaz << " " << sontuketimyil << " " << yuzgramdakalori << " " << stokadeti << " " << birimmiktargelisfiyati << " " << birimmiktarsatisfiyati << " " << endl;
                        }
                        depotxteksikmalzemeciktiyaz.close();
                        depotxtoku.close();
                    }
                    ifstream depotxtoku("depo.txt");
                    ofstream depotxtyaz("depoyedek.txt");
                    while (depotxtoku >> urunadi >> uretildigigun >> uretildigiay >> uretildigiyil >> sontuketimgun >> sontuketimay >> sontuketimyil >> yuzgramdakalori >> stokadeti >> birimmiktargelisfiyati >> birimmiktarsatisfiyati) {
                        ificinstokadetikontrolu = stokadeti - uretilmekistenenyemeksayisi * kullanilacakmiktar; // depo verileri okunuyor
                        elseifcalistimi = 0;
                        eksikciktimi = 0;
                        if (kullanilacakmalzeme == urunadi) { //okunan urun adi tarifteki urun adiyla ayniysa bu blok calisiyor
                            if (ificinstokadetikontrolu < 0) { //eger istenen urunden yeterli sayida yoksa calisan blok

                                cout << "\n bu yemekten istediginiz adette yapmaniza yetecek malzeme elinizde yok.\n";
                                cout << "\n stok durumunuz bir onceki haline dondurulmustur \n";
                                ifstream depotxteksikmalzemeciktioku("depoyedekeksikkaynak.txt");
                                ofstream depotxtmalzemetksikciktiyaz("depoyedekeksikhedef.txt");
                                while (depotxteksikmalzemeciktioku >> urunadi >> uretildigigun >> uretildigiay >> uretildigiyil >> sontuketimgun >> sontuketimay >> sontuketimyil >> yuzgramdakalori >> stokadeti >> birimmiktargelisfiyati >> birimmiktarsatisfiyati)
                                { // stoklar duzeltiliyor
                                    depotxtmalzemetksikciktiyaz << " " << urunadi << " " << uretildigigun << " " << uretildigiay << " " << uretildigiyil << " " << sontuketimgun << " " << sontuketimay;
                                    depotxtmalzemetksikciktiyaz << " " << sontuketimyil << " " << yuzgramdakalori << " " << stokadeti << " " << birimmiktargelisfiyati << " " << birimmiktarsatisfiyati << " " << endl;
                                }
                                eksikciktimi = 1;

                                depotxtyaz.close();
                                depotxtoku.close();

                                depotxteksikmalzemeciktioku.close();
                                depotxtmalzemetksikciktiyaz.close(); //dosyalarimiz tekrar acilmak uzere kapaniyor cunku eksik malzeme cikti ve stoklarimizi korumamiz gerekiyor
                                malzemetxtoku.close();
                                remove("depoyedekeksikkaynak.txt");
                                remove("depo.txt");
                                rename("depoyedekeksikhedef.txt", "depo.txt");
                                remove("depoyedek.txt");
                            }
                            else if (ificinstokadetikontrolu >= 0) { //urunden istenen miktarda varsa calisan kod 

                                if (eksikciktimi == 0) { //eger eksik malzeme cikmadiysa buradan okunmaya devam ediyor eger sonrasinda eksik malzeme cikarsa stoklar duzeltilip buranin bu yemek icin tekrar calismasi engelleniyor
                                    elseifcalistimi = 1;
                                    yemekicinihtiyacduyulanmalzemeraporundagosterilecekmaliyet = uretilmekistenenyemeksayisi * birimmiktargelisfiyati * kullanilacakmiktar;
                                    toplammaliyetilkdeger = uretilmekistenenyemeksayisi * birimmiktargelisfiyati * kullanilacakmiktar;
                                    toplammaliyetsondeger += toplammaliyetilkdeger;
                                    toplammaliyetkontroldegeri -= toplammaliyetilkdeger;

                                    cout << "\n" << yemekadi << " isimli yemekten " << uretilmekistenenyemeksayisi << " porsiyon uretmek icin  " << uretilmekistenenyemeksayisi * kullanilacakmiktar << " kadar (kg veya l) " << kullanilacakmalzeme << " ye ihtiyac vardir";
                                    cout << " ve bunun maliyeti " << yemekicinihtiyacduyulanmalzemeraporundagosterilecekmaliyet << " TL'dir. ve bu besinin 100 gramda kalorisi " << yuzgramdakalori << " dir  " << endl;
                                    //depotxtden stok dusuluyor
                                    depotxtyaz << " " << urunadi << " " << uretildigigun << " " << uretildigiay << " " << uretildigiyil << " " << sontuketimgun << " " << sontuketimay << " ";
                                    depotxtyaz << sontuketimyil << " " << yuzgramdakalori << " " << stokadeti - (uretilmekistenenyemeksayisi * kullanilacakmiktar) << " " << birimmiktargelisfiyati << " " << birimmiktarsatisfiyati << " " << endl;
                                }
                                if (eksikciktimi == 1) { //eksik urun ciktiysa kar zarar miktarini duzenlemeye yarayan kod
                                    toplammaliyetsondeger = toplammaliyetsondeger - toplammaliyetkontroldegeri;

                                }
                            }


                        }
                        else {
                            if (eksikciktimi == 0) { //eksik malzeme cikmadiysa kullanilmayan malzeme bilgileri aynen yaziliyor eger eksik ciktiysa bu yemek icin bu blok bir daha calismiyor
                                depotxtyaz << " " << urunadi << " " << uretildigigun << " " << uretildigiay << " " << uretildigiyil << " " << sontuketimgun << " " << sontuketimay << " ";
                                depotxtyaz << sontuketimyil << " " << yuzgramdakalori << " " << stokadeti << " " << birimmiktargelisfiyati << " " << birimmiktarsatisfiyati << " " << endl;
                            }
                        }

                    }
                    if (eksikciktimi == 0) {// eksik malzeme cikmadiysa dosyalari tekrar acabilmek icin burada kapatiyoruz eger eksik malzeme cikc=saydi kapatma islemi yukarida yapailacakti
                        depotxtyaz.close();
                        depotxtoku.close();
                        remove("depo.txt");
                        remove("depoyedekeksikkaynak.txt");
                        rename("depoyedek.txt", "depo.txt");
                    }


                }


            }
            malzemetxtoku.close();

            if (eksikciktimi == 0) { //eksik malzeme cikmadiysa yemegin ismi uretilen yemek dosyamiza yaziliyor(eldekiyemek.txt)
                eldekiyemektxtyaz << " " << yemekadi << " " << uretilmekistenenyemeksayisi << " " << endl;
            }




        }
        eldekiyemektxtyaz.close();

    }
    void yemeksatisfonksiyonu() { //urettigimiz yemekleri satmaya yarayan fonksiyon
        ifstream eldekiyemektxtoku("eldekiyemek.txt");
        int satisyapmakistenensayi;
        ofstream gunsonueldekalanyemeksayilari("eldekalanyemek.txt");
        while (eldekiyemektxtoku >> eldekiyemektxticinyemekadi >> eldekiyemektxticineldekiyemeksayisi) { //eldeki yemektxtden urettigimiz yemekler okunuyor
            ifstream malzemetxtoku("malzeme.txt");
            cout << "\n\n lutfen " << eldekiyemektxticinyemekadi << " isimli yemekten kac porsiyon satmak istediginizi giriniz (bu yemekten en fazla " << eldekiyemektxticineldekiyemeksayisi << " kadar satabilirsiniz) \n\n";
            do {
                cin >> satisyapmakistenensayi; //uretilenden fazla satilmak istenen yemek sayii girilmesin diye kontrol ediliyor
            } while (!((eldekiyemektxticineldekiyemeksayisi >= satisyapmakistenensayi) && (satisyapmakistenensayi > 0)));
            cout << " girdiginiz deger gecerli sonraki isleme aktariliyorsunuz \n\n";
            while (malzemetxtoku >> malzemelerdekullanmakicinyemekadi >> kullanilacakmiktar >> kullanilacakmalzeme) { //malzeme isimleri okunuyor
                if (eldekiyemektxticinyemekadi == malzemelerdekullanmakicinyemekadi) { // eger malzeme dosyasindaki yemek ismi uretilen ve satilmak istenen yemege esitse bu kod blogu calisiyor
                    ifstream depotxtoku("depo.txt");

                    while (depotxtoku >> urunadi >> uretildigigun >> uretildigiay >> uretildigiyil >> sontuketimgun >> sontuketimay >> sontuketimyil >> yuzgramdakalori >> stokadeti >> birimmiktargelisfiyati >> birimmiktarsatisfiyati) {
                        //depodan urun bilgileri okunuyor
                        if (kullanilacakmalzeme == urunadi) { //okunan malzeme ismi urunadi ile ayniysa bu blok calisiyor ve alinan parayi hesapliyor

                            toplamparagirisilkdeger += kullanilacakmiktar * birimmiktarsatisfiyati * satisyapmakistenensayi;

                        }

                    }
                    depotxtoku.close();
                }

            }


            malzemetxtoku.close();
            gunsonueldekalanyemeksayilari << " " << eldekiyemektxticinyemekadi << " " << (eldekiyemektxticineldekiyemeksayisi - satisyapmakistenensayi) << " " << endl; //elde kalan yemek isimleri ve sayilari dosyaya yaziliyor
        }

        eldekiyemektxtoku.close();
        gunsonueldekalanyemeksayilari.close();
    }

    void stokyenilemefonksiyonu() { //stogu kritik duzeyde olan urunlerden alisveris yapmamizi saglayan kod blogu
        ifstream depotxtoku("depo.txt");
        ofstream depotxtyaz("depostokyenileme.txt");
        int stogaeklenmekistenensayi;
        int stokyenilemeisteniyormuistenmiyormu;
        int alisveristeharcananpara = 0;
        float goruntulenmekistenenmaksstok;
        cout << "\n \n \n \n";
        cout << "yaptiginiz alisverisler gun ici harcanan para miktarina yazilacaktir\n";
        cout << "\n lutfen depodan maksimum stogu kac olan urunlerden alisveris yapmak istediginizi giriniz\n";
        cin >> goruntulenmekistenenmaksstok;
        while (depotxtoku >> urunadi >> uretildigigun >> uretildigiay >> uretildigiyil >> sontuketimgun >> sontuketimay >> sontuketimyil >> yuzgramdakalori >> stokadeti >> birimmiktargelisfiyati >> birimmiktarsatisfiyati) {
            //depodan bilgiler okunuyor
            if (stokadeti <= goruntulenmekistenenmaksstok) { //stok adeti goruntulenmek istenen degerden kucuk mu kontrol eden kod

                cout << "urunun adi: " << urunadi << " bu urunden elinizde gormek istediginiz birimden az kaldi stogu yenilemek ister misiniz? eger istiyorsaniz 1 giriniz" << endl;
                cin >> stokyenilemeisteniyormuistenmiyormu;
                if (stokyenilemeisteniyormuistenmiyormu == 1) { //eger stok yenilenmek isteniyorsa stogu yenilemeye yarayan kod (istenip istenmedigini kontrol eden if)
                    cout << " lutfen urunden kac birim siparis etmek istediginizi giriniz.\n";
                    cin >> stogaeklenmekistenensayi;
                    depotxtyaz << " " << urunadi << " " << uretildigigun << " " << uretildigiay << " " << uretildigiyil << " " << sontuketimgun; //guncel veriler depoya isleniyor
                    depotxtyaz << " " << sontuketimay << " " << sontuketimyil << " " << yuzgramdakalori << " " << stogaeklenmekistenensayi << " " << birimmiktargelisfiyati << " " << birimmiktarsatisfiyati << " " << endl;
                    toplammaliyetsondeger += (birimmiktargelisfiyati * stogaeklenmekistenensayi);
                    alisveristeharcananpara += (birimmiktargelisfiyati * stogaeklenmekistenensayi);
                }


                else { // stok yenilenmek istenmiyorsa verileri guncel dosyaya isleyen kod(stok goruntulenmek istenen seviyedeyse cunku stok kontrolu ifinin icinde)
                    depotxtyaz << " " << urunadi << " " << uretildigigun << " " << uretildigiay << " " << uretildigiyil << " " << sontuketimgun;
                    depotxtyaz << " " << sontuketimay << " " << sontuketimyil << " " << yuzgramdakalori << " " << stokadeti << " " << birimmiktargelisfiyati << " " << birimmiktarsatisfiyati << " " << endl;
                }
            }
            else {// stok yenilenmek istenmiyorsa verileri guncel dosyaya isleyen kod

                depotxtyaz << " " << urunadi << " " << uretildigigun << " " << uretildigiay << " " << uretildigiyil << " " << sontuketimgun;
                depotxtyaz << " " << sontuketimay << " " << sontuketimyil << " " << yuzgramdakalori << " " << stokadeti << " " << birimmiktargelisfiyati << " " << birimmiktarsatisfiyati << " " << endl;

            }
        }
        depotxtyaz.close();
        depotxtoku.close();
        remove("depo.txt");
        rename("depostokyenileme.txt", "depo.txt");
        cout << "\n\n\n stoklariniz basariyla yenilenmistir bu alisveriste harcadiginiz para" << alisveristeharcananpara << " TL'dir \n\n\n";
    }


    void gunsonuraporugostermefonksiyonu() { //gun sonu raporu almamizi saglayan fonksiyon
        int uretilmekistenenyemeksayisiwhileicindekullanmakicin;
        int sattigimizyemeksayisi;
        {
            ifstream eldekiyemektxtoku("eldekiyemek.txt");
            cout << "\n\n\n\n";
            while (eldekiyemektxtoku >> yemekadi >> uretilmekistenenyemeksayisiwhileicindekullanmakicin) { // eldeki yemek dosyasindan urettigimiz yemek miktari okunuyor 
                cout << yemekadi << " adli yemekten " << uretilmekistenenyemeksayisiwhileicindekullanmakicin << " porsiyon uretildi";
            }
            eldekiyemektxtoku.close();
        }
        {
            ifstream eldekiyemektxtoku("eldekiyemek.txt");
            ifstream eldekalanyemeksayilaritxtoku("eldekalanyemek.txt");
            while (eldekiyemektxtoku >> yemekadi >> uretilmekistenenyemeksayisiwhileicindekullanmakicin) {  //eldeki yemek dosyasindan urettigimiz yemek miktari okunuyor (aritmatik islem icin)
                ifstream eldekalanyemeksayilaritxtoku("eldekalanyemek.txt");
                while (eldekalanyemeksayilaritxtoku >> eldekalanyemekadlari >> eldekalanyemeksayisi) { //elde kalan yemek dosyasindan elde kalan yemek sayisi oknuyor (aritmatik islem icin)
                    if (eldekalanyemekadlari == yemekadi) {
                        sattigimizyemeksayisi = uretilmekistenenyemeksayisiwhileicindekullanmakicin - eldekalanyemeksayisi;
                        cout << "\n" << yemekadi << " adli yemekten " << sattigimizyemeksayisi << " porsiyon satildi \n";
                    }

                }
                eldekalanyemeksayilaritxtoku.close();
            }
            eldekiyemektxtoku.close();
        }

        {       ifstream eldekalanyemeksayilaritxtoku("eldekalanyemek.txt");
        cout << " \n\n\n\n";
        while (eldekalanyemeksayilaritxtoku >> eldekalanyemekadlari >> eldekalanyemeksayisi) { //elde kalan yemek dosyasindan elde kalan yemekler ve miktarlari okunuyor (goruntulenmek icin)
            cout << eldekalanyemekadlari << " adli yemekten elinizde " << eldekalanyemeksayisi << " porsiyon kaldi\n";
        }
        eldekalanyemeksayilaritxtoku.close();
        }
        cout << "\n\n\n" << " bugun toplam para girdiniz: " << toplamparagirisilkdeger << " TLdir " << endl;
        cout << " bugun toplam para ciktiniz: " << toplammaliyetsondeger << " TLdir " << endl;
        cout << "bugun toplam net kazanciniz: " << toplamparagirisilkdeger - toplammaliyetsondeger << " TLdir " << endl;

    }
};



int main()
{
    urun nesne1;
    yemekcesit nesne2;
    int urunmenusukontroldegiskeni1;
    int urunmenusukontroldegiskeni2; //degiskenlerimiz
    int yemekmenusukontroldegiskeni1;
    int yemekmenusukontroldegiskeni2;
    int yemekuretimmenusukontroldegiskeni1;
    int yemekuretimmenusukontroldegiskeni2;
    int sonrakigunegecmekontroludegiskeni;
    int gunsayaci = 1;
    do {//gun dongusunu kontrol eden do while
        nesne2.toplammaliyetifdegeri = 0;
        nesne2.toplammaliyetilkdeger = 0; //onceki gunden kalan veriler resetleniyor
        nesne2.toplammaliyetkontroldegeri = 0;
        nesne2.toplammaliyetsondeger = 0;
        nesne2.toplamparagirisilkdeger = 0;
        nesne2.toplamparagirisilkdeger = 0;
        cout << "\n\n***********************************************************************************************TUGRA LOKANTASI BILGI SISTEMI**********************************************************************************************\n\n";
        cout << "\n\n" << gunsayaci << ". gun \n\n";
        do {//depoda baska islem yapilmak isteniyor mu kontrol eden do while
            do {//depoda yapilmak istenen islem gecerli mi kontrol eden do while
                cout << " depodaki urunleriniz hakkinda yapmak istediginiz islemi seciniz" << endl;
                cout << "1. islem urunler hakkinda rapor al \n";
                cout << "2. islem urun ekle\n";
                cout << "3. islem urun sil\n";
                cout << "4. islem urun bilgileri guncelle\n\n";
                cout << " lutfen hangi islemi yapmak istediginizi seciniz (1-4) giriniz\n";
                cin >> urunmenusukontroldegiskeni1;
                if (urunmenusukontroldegiskeni1 == 1) {
                    nesne1.depotxtraporalma(); //depoda yapilmak istenen islemi kontrol eden if
                }
                else if (urunmenusukontroldegiskeni1 == 2) {
                    nesne1.depotxtkayitekleme();//depoda yapilmak istenen islemi kontrol eden if
                }
                else if (urunmenusukontroldegiskeni1 == 3) {
                    nesne1.depotxtkayitsilme();//depoda yapilmak istenen islemi kontrol eden if
                }
                else if (urunmenusukontroldegiskeni1 == 4) {
                    nesne1.depobilgileriguncellemefonksiyonu();
                }//depoda yapilmak istenen islemi kontrol eden if
                else {
                    cout << "lutfen 1 ile 4 arasinda bir sayi giriniz" << endl; //depoda yapilmak istenen islem gecerli degilse calisan kod blogu
                }


            } while (!(urunmenusukontroldegiskeni1 >= 1 && urunmenusukontroldegiskeni1 <= 4)); //depoda yapilmak istenen islem gecerli mi kontrol eden do while
            cout << "\n depo icin baska islemde bulunmak ister misiniz? eger istiyorsaniz 1 tuslayiniz \n";
            cin >> urunmenusukontroldegiskeni2;

        } while (urunmenusukontroldegiskeni2 == 1);//depoda baska islem yapilmak isteniyor mu kontrol eden do while
        do {//yemek cesitleri hakkinda baska islem yapilmak isteniyor mu kontrol eden do while
            do {//yapilmak istenen islem gecerli mi kontrol eden do while 
                cout << "\n\n yemek cesiti ve tarifleri menunuze hos geldiniz. lutfen yapmak istediginiz islemi seciniz\n\n";
                cout << "1. islem yemek cesitleri hakkinda rapor alma \n";
                cout << "2. islem yemek cesiti ekleme\n";
                cout << "3. islemyemek cesiti silme\n";
                cout << "4. isle yemek cesiti bilgisi/bilgileri hakkinda guncelleme yapma\n";
                cout << " lutfen hangi islemi yapmak istediginizi seciniz (1-4) giriniz\n";
                cin >> yemekmenusukontroldegiskeni1;
                if (yemekmenusukontroldegiskeni1 == 1) {
                    nesne2.yemekcesiticinraporalma(); //yemekcesitlerinde yapilmak istenen islemi kontrol eden if
                }
                else if (yemekmenusukontroldegiskeni1 == 2) {
                    nesne2.yemekcesittxtkayitekleme();//yemekcesitlerinde yapilmak istenen islemi kontrol eden if
                }
                else if (yemekmenusukontroldegiskeni1 == 3) {//yemekcesitlerinde yapilmak istenen islemi kontrol eden if
                    nesne2.yemekcesittxticinkayitsilme();
                }
                else if (yemekmenusukontroldegiskeni1 == 4) {
                    nesne2.yemekcesiticinguncelleme();//yemekcesitlerinde yapilmak istenen islemi kontrol eden if
                }
                else {
                    cout << "lutfen 1 ile 4 arasinda bir sayi giriniz" << endl; //yapilmak istenen islem gecerli degilse calisan kod blogu
                }
            } while (!(yemekmenusukontroldegiskeni1 >= 1 && yemekmenusukontroldegiskeni1 <= 4));//yapilmak istenen islem gecerli mi kontrol eden do while 
            cout << " \n bu menude baska islem yapmak ister misiniz istiyorsaniz 1 tuslayiniz." << endl;
            cin >> yemekmenusukontroldegiskeni2;
        } while (yemekmenusukontroldegiskeni2 == 1);//yemek cesitleri hakkinda baska islem yapilmak isteniyor mu kontrol eden do while
        do { //yemek uretim satim menusunde baska islem yapilmak isteniyor mu kontrol eden kod
            do {//yemek uretim satim menusunde yapilmak istenen islem gecerli mi kontrol eden kod
                cout << "\n\n\n urun/yemek uretim satim menusune hos geldiniz lutfen yapmak istediginiz islemi seciniz\n\n\n";
                cout << "1.islem stok guncelleme\n";
                cout << "2. islem yemek uretimi\n";
                cout << "3. islem yemek satimi\n";
                cout << "lutfen yapmak istediginiz islemi giriniz (1-3) \n";
                cin >> yemekuretimmenusukontroldegiskeni1;
                if (yemekuretimmenusukontroldegiskeni1 == 1) {
                    nesne2.stokyenilemefonksiyonu(); //yemek uretim satim menusunde yapilamk istenen islemi kontrol eden if
                }
                else if (yemekuretimmenusukontroldegiskeni1 == 2) {
                    nesne2.yemekuretimfonksiyon();//yemek uretim satim menusunde yapilamk istenen islemi kontrol eden if
                }
                else if (yemekuretimmenusukontroldegiskeni1 == 3) {
                    nesne2.yemeksatisfonksiyonu();//yemek uretim satim menusunde yapilamk istenen islemi kontrol eden if
                }
                else {//yapilmak istenen islem gecerli degilse calisan kod blogu
                    cout << "lutfen 1 ile 4 arasinda bir sayi giriniz" << endl;
                }
            } while (!(yemekuretimmenusukontroldegiskeni1 >= 1 && yemekuretimmenusukontroldegiskeni1 <= 3));//yemek uretim satim menusunde yapilmak istenen islem gecerli mi kontrol eden kod
            cout << "bu menude baska islem yapmak ister misiniz isterseniz 1 tuslayiniz\n";
            cin >> yemekuretimmenusukontroldegiskeni2;
        } while (yemekuretimmenusukontroldegiskeni2 == 1);//yemek uretim satim menusunde baska islem yapilmak isteniyor mu kontrol eden kod
        cout << "\n\n\n\n gun sonu raporunuz asagidaki sekildedir:\n\n";
        nesne2.gunsonuraporugostermefonksiyonu(); //gun sonu rapor gosterimi yapiliyor
        cout << "sonraki gune gecmek ister misiniz istiyorsaniz 1 tuslayiniz\n";
        cout << "*****eger sonraki gune gecmek istemezseniz sistem kapatilacaktir*****\n";
        cin >> sonrakigunegecmekontroludegiskeni;
        gunsayaci++;
        remove("eldekalanyemek.txt");
        remove("eldekiyemek.txt");
    } while (sonrakigunegecmekontroludegiskeni == 1);//gun dongusunu kontrol eden do while
    return 0;
}