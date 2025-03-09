//
//  main.c
//  avp_donem_projesi
//
//  Created by Erva Aygüneş ve Sude Naz Doğdu.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Karakter nitelikleri ve becerileri için değişkenler
int can = 100, tokluk = 100, uyku = 100, hijyen = 100;
int moral = 100, stres = 0, enerji = 100;
int seviye = 1, tecrube = 0, altin = 10;

// Beceriler
int guc = 3, ceviklik = 3, dayaniklilik = 3, karizma = 3, toplayicilik = 3;

// Fonksiyonlar
void karakterDurumuGoster() {
    printf("\n--- Karakter Durumu ---\n");
    printf("Can: %d | Tokluk: %d | Uyku: %d | Hijyen: %d\n", can, tokluk, uyku, hijyen);
    printf("Moral: %d | Stres: %d | Enerji: %d | Altin: %d\n", moral, stres, enerji, altin);
    printf("Seviye: %d | Tecrübe: %d\n", seviye, tecrube);
    printf("Guc: %d | Ceviklik: %d | Dayaniklilik: %d | Karizma: %d | Toplayicilik: %d\n", guc, ceviklik, dayaniklilik, karizma, toplayicilik);
}

void kampAlani() {
    int secim;
    printf("\n--- Kamp Alani ---\n");
    printf("1. Kamp atesinde sarki soyle.\n");
    printf("2. Nehirde yikan.\n");
    printf("3. Cadirina girip uyu.\n");
    printf("4. Koy meydanina don.\n");
    printf("Secim: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1:
            printf("Sarki soylediniz ve moraliniz artti!\n");
            moral += 10; stres -= 5; tokluk -= 5;
            if (moral >= 100) printf("Moral seviyeniz maksimum! Keyfini cikarin:)\n");
            else printf("Yeni moral seviyeniz: %d\n", moral);

            if (stres <= 0) printf("Stres seviyeniz minimum! Keyfini cikarin:)\n");
            else printf("Yeni stres seviyeniz: %d\n", stres);

            if (tokluk <= 0) printf("Toklugunuz cok düsük! Ac kalmamaya dikkat edin.\n");
            else printf("Yeni tokluk seviyeniz: %d\n", tokluk);
            break;

        case 2:
            printf("Nehirde yikandiniz ve hijyeniniz artti!\n");
            hijyen += 20; enerji -= 5;
            if (hijyen >= 100) printf("Hijyen seviyeniz maksimum! Keyfini cikarin:)\n");
            else printf("Yeni hijyen seviyeniz: %d\n", hijyen);

            if (enerji <= 0) printf("Enerjiniz cok düsük! Dinlenmeye ihtiyaciniz var.\n");
            else printf("Yeni enerji seviyeniz: %d\n", enerji);
            break;

        case 3:
            printf("Cadirinizda uyudunuz. Uyku ve enerji yenilendi!\n");
            uyku += 30; enerji += 20; tokluk -= 10;
            if (uyku >= 100) printf("Uykunuzu tamamen almissiniz! Keyfini cikarin:)\n");
            else printf("Yeni uyku seviyeniz: %d\n", uyku);

            if (enerji >= 100) printf("Enerji seviyeniz maksimum! Keyfini cikarin:)\n");
            else printf("Yeni enerji seviyeniz: %d\n", enerji);

            if (tokluk <= 0) printf("Toklugunuz cok düsük! Ac kalmamaya dikkat edin.\n");
            else printf("Yeni tokluk seviyeniz: %d\n", tokluk);
            karizma-=2;
            dayaniklilik+=1;
            if (dayaniklilik > 25) dayaniklilik = 25; // Dayaniklilik sýnýrý
            if (karizma > 25) karizma = 25;
            break;

        default:
            printf("Koy meydanina donuyorsunuz...\n");
            break;
    }
}

void sifahane() {
    int secim;
    printf("\n--- Sifahane ---\n");
    printf("1. Yaralarinizi sarin (10 altin).\n");
    printf("2. Merhem yapin (5 altin).\n");
    printf("3. Koy meydanina don.\n");
    printf("Secim: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1:
            printf("Yaralarinizi sardiniz...\n");
            if (altin >= 10) {
                can += 20; altin -= 10;
                if (can >= 100) printf("Caniniz maksimum seviyede! Sagliginiz yerinde:)\n");
                else printf("Yeni can seviyeniz: %d\n", can);
            } else {
                printf("Yeterli altininiz yok!\n");
            }
            karizma+=1;
            dayaniklilik+=1;
            if (dayaniklilik > 25) dayaniklilik = 25; // Dayaniklilik siniri
            if (karizma > 25) karizma = 25;
            break;

        case 2:
            printf("Merhem yaptiniz...\n");
            if (altin >= 5) {
                can += 10; altin -= 5;
                if (can >= 100) printf("Caniniz maksimum seviyede! Sagliginiz yerinde:)\n");
                else printf("Yeni can seviyeniz: %d\n", can);
            } else {
                printf("Yeterli altininiz yok!\n");
            }
            karizma+=1;
            if (karizma > 25) karizma = 25;
            break;

        default:
            printf("Koy meydanina donuyorsunuz...\n");
            break;
    }
}

void han() {
    int secim;
    printf("\n--- Han ---\n");
    printf("1. Yiyecek satin al ve ye (5 altin).\n");
    printf("2. Enstruman cal ve sarki soyle.\n");
    printf("3. Icecek satin al, ic ve eglen (8 altin).\n");
    printf("4. Koy meydanina don.\n");
    printf("Secim: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1:
            if (altin >= 5) {
                printf("Yemek yediniz ve toklugunuz artti!\n");
                tokluk += 20; altin -= 5;
                if (tokluk >= 100) printf("Tokluk seviyeniz maksimum! Doymus hissediyorsunuz:)\n");
                else printf("Yeni tokluk seviyeniz: %d\n", tokluk);
            } else {
                printf("Yeterli altininiz yok!\n");
            }
            break;

        case 2:
            printf("Sarki soylediniz, karizmaniz etkilendi!\n");
            altin += 10 + (karizma * hijyen) / 100;
            printf("Yeni altin miktariniz: %d\n", altin);
            karizma+=3;
            if (karizma > 25) karizma = 25;
            printf("Yeni karizma miktariniz: %d\n", karizma);
            break;

        case 3:
            if (altin >= 8) {
                printf("Içecek satin alip içtiniz. Moraliniz artti, stresiniz azaldi!\n");
                moral += 15; stres -= 10; altin -= 8;
                if (moral >= 100) printf("Moral seviyeniz maksimum! Keyfini cikarin:)\n");
                else printf("Yeni moral seviyeniz: %d\n", moral);

                if (stres <= 0) printf("Stres seviyeniz minimum! Keyfini cikarin:)\n");
                else printf("Yeni stres seviyeniz: %d\n", stres);
            } else {
                printf("Yeterli altininiz yok!\n");
            }
            karizma+=1;
            if (karizma > 25) karizma = 25;
            break;

        default:
            printf("Koy meydanina donuyorsunuz...\n");
            break;
    }
}



void macerayaAtil() {
    int secim, sans, haydutGuc, haydutCeviklik, haydutDayaniklilik;
    int bitkiSans = (toplayicilik * 4) / 100; // sifali bitki bulma sansi
    int kacmaIhtimali, tur = 1; // Kaçma ve tur sayaclari
    int ozanHasar, haydutHasar; // Hasar deðerleri
    int baslangicCan = can; // savas öncesi can durumu
    int baslangicEnerji = enerji;
    int baslangicTokluk = tokluk;
    int baslangicAltin = altin; // baslangic altini
    int baslangicTecrube = tecrube; // baslangic tecrübesi
    int baslangicStres = stres; // baslangic stresi

    srand(time(0)); // Rastgele sayi üretimi için baslangic

    printf("\n--- Maceraya Atil ---\n");
    printf("1. Yakin cevrede sifali bitki topla ve avlan.\n");
    printf("2. Ormani kesfe cik (Kolay).\n");
    printf("3. Kayaliklari kesfe cik (Orta).\n");
    printf("4. Vadiyi kesfe cik (Zor).\n");
    printf("5. Koy meydanina don.\n");
    printf("Secim: ");
    scanf("%d", &secim);

    switch (secim) {
        case 1: // sifali bitki toplama ve avlan
            sans = rand() % 100; // 0-99 arasi rastgele sayi

            if (sans < bitkiSans) {
                printf("Tebrikler! Sifali bitki buldunuz. Caniniz 10 artti.\n");
                can += 10;
                if (can >= 100) printf("Caniniz maksimum seviyede! Sagliginiz yerinde:)\n");
            } else if (sans < bitkiSans * 2) {
                printf("Meyve topladiniz. Toklugunuz 10 artti.\n");
                tokluk += 10;
                if (tokluk >= 100) printf("Tokluk seviyeniz maksimum! Doymus hissediyorsunuz:)\n");
            } else if (sans < bitkiSans * 3) {
                printf("Bir av hayvani avladiniz. Toklugunuz 50 artti.\n");
                tokluk += 50;
                if (tokluk >= 100) printf("Tokluk seviyeniz maksimum! Doymus hissediyorsunuz:)\n");
            } else {
                printf("Hiçbir sey bulamadiniz. Sansinizi bir daha deneyin!\n");
            }
            toplayicilik+=1;
            if (toplayicilik > 25) toplayicilik = 25;
            break;

        case 2: // Kolay kesif
            haydutGuc = rand() % 3 + 1;
            haydutCeviklik = rand() % 3 + 1;
            haydutDayaniklilik = rand() % 3 + 1;
            printf("\nOrmanda bir haydut yolunuzu kesti! Haydut Gucu: %d, Ceviklik: %d, Dayaniklilik: %d\n",
                   haydutGuc, haydutCeviklik, haydutDayaniklilik);
            enerji -= 10;
            tokluk -= 10;
            stres += 10;
            karizma-=1;
            dayaniklilik+=1;
            guc+=1;
            ceviklik+=1;
            tecrube+=20;
            if (tecrube > 100) tecrube = 100;
            if (ceviklik > 25) ceviklik = 25;
            if (guc > 25) guc = 25;
            if (dayaniklilik > 25) dayaniklilik = 25;
            if (karizma > 25) karizma = 25;

            break;

        case 3: // Orta kesif
            haydutGuc = rand() % 3 + 4;
            haydutCeviklik = rand() % 3 + 4;
            haydutDayaniklilik = rand() % 3 + 4;
            printf("\nKayaliklarda bir haydutla karsilastiniz! Haydut Gucu: %d, Ceviklik: %d, Dayaniklilik: %d\n",
                   haydutGuc, haydutCeviklik, haydutDayaniklilik);
            enerji -= 15;
            tokluk -= 15;
            stres += 15;
            karizma-=2;
            dayaniklilik+=2;
            guc+=2;
            ceviklik+=2;
            tecrube+=20;
            if (tecrube > 100) tecrube = 100;
            if (ceviklik > 25) ceviklik = 25;
            if (guc > 25) guc = 25;
            if (dayaniklilik > 25) dayaniklilik = 25;
            if (karizma > 25) karizma = 25;
            break;

        case 4: // Zor keþif
            haydutGuc = rand() % 4 + 7;
            haydutCeviklik = rand() % 4 + 7;
            haydutDayaniklilik = rand() % 4 + 7;
            printf("\nVadide zorlu bir haydutla savasiyorsunuz! Haydut Gucu: %d, Ceviklik: %d, Dayaniklilik: %d\n",
                   haydutGuc, haydutCeviklik, haydutDayaniklilik);
            enerji -= 20;
            tokluk -= 20;
            stres += 20;
            karizma-=3;
            dayaniklilik+=3;
            guc+=3;
            ceviklik+=3;
            tecrube+=20;
            if (tecrube > 100) tecrube = 100;
            if (ceviklik > 25) ceviklik = 25;
            if (guc > 25) guc = 25;
            if (dayaniklilik > 25) dayaniklilik = 25;
            if (karizma > 25) karizma = 25;
            break;

        default:
            printf("Koy meydanina donuyorsunuz...\n");
            return;
    }

    // Kaçma ve savas seçenekleri
    printf("\n1. Savas\n2. Kacmaya Calis\nSeciminiz: ");
    scanf("%d", &secim);

    if (secim == 2) { // Kaçma seçenegi
        kacmaIhtimali = (4 * ceviklik) / 100;
        sans = rand() % 100;
        if (sans < kacmaIhtimali) {
            printf("Basariyla kactiniz! Haydut sizi takip edemedi.\n");
            return;
        } else {
            printf("Kacamadiniz! Haydut size saldiriyor.\n");
        }
    }

    // **savaş başladı**
    printf("\n--- Savas Basladi! ---\n");

    // **savaş mekaniği**
    while (can > 0 && haydutDayaniklilik > 0) {
        printf("\n--- Tur %d ---\n", tur++);

        // saldıran taraf belirleniyor
        if (ceviklik > haydutCeviklik) {
            ozanHasar = 4 * guc;
            haydutHasar = 4 * haydutGuc - (4 * dayaniklilik) / 100 - 1;

            printf("Saldirdiniz! Hayduta %d hasar verdiniz.\n", ozanHasar);
            haydutDayaniklilik -= ozanHasar;

            if (haydutDayaniklilik <= 0) {
                printf("Haydutu yendiniz! Kazandiniz.\n");
                break;
            }

            printf("Haydut size saldirdi! %d hasar aldiniz.\n", haydutHasar);
            can -= haydutHasar;

        } else {
            haydutHasar = 4 * haydutGuc;
            ozanHasar = 4 * guc - (4 * haydutDayaniklilik) / 100 - 1;

            printf("Haydut size saldirdi! %d hasar aldiniz.\n", haydutHasar);
            can -= haydutHasar;

            if (can <= 0) {
                printf("Ozan yenildi! Macera burada sona eriyor.\n");
                exit(0);
            }

            printf("Saldirdiniz! Hayduta %d hasar verdiniz.\n", ozanHasar);
            haydutDayaniklilik -= ozanHasar;
        }
    }

    // Altýn ve tecrübe kazancý yazdýrma
    printf("Baslangic Altin: %d -> Guncel Altin: %d\n", baslangicAltin, altin);
    printf("Baslangic Tecrube: %d -> Guncel Tecrube: %d\n", baslangicTecrube, tecrube);

    if (can > 0) {
        printf("\nSavas bitti! Haydutu yendiniz.\n");
        altin += 10;
        tecrube += 20;
        printf("Kazandiginiz Altin: 10 | Kazandiginiz Tecrube: 20\n");
    }

    // Sýnýrlarýn kontrolü
    if (can > 100) can = 100;
    if (tokluk > 100) tokluk = 100;

    // Azalma sonrasý durum mesajlarý
    if (tokluk <= 0) printf("Toklugunuz cok düsük! Ac kalmamaya dikkat edin.\n");
    else printf("Yeni tokluk seviyeniz: %d\n", tokluk);

    if (enerji <= 0) printf("Enerjiniz cok düsük! Dinlenmeye ihtiyaciniz var.\n");
    else printf("Yeni enerji seviyeniz: %d\n", enerji);

    // **savaş sonrası** Azalma (enerji, tokluk)
    printf("\n--- Savas Sonu Durum ---\n");
    printf("Baslangic Can: %d -> Guncel Can: %d\n", baslangicCan, can);
    printf("Baslangic Enerji: %d -> Guncel Enerji: %d\n", baslangicEnerji, enerji);
    printf("Baslangic Tokluk: %d -> Guncel Tokluk: %d\n", baslangicTokluk, tokluk);
    printf("Baslangic Stres: %d -> Guncel Stres: %d\n", baslangicStres, stres);
}

int main() {
    int secim;
    char isim[20], calgi[20];

    printf("Ozanin adini giriniz: ");
    scanf("%s", isim);
    printf("Ozanin calgisini giriniz: ");
    scanf("%s", calgi);

    printf("Hosgeldin %s! Maceraya hazir misin?\n", isim);

    while (1) {
        printf("\n--- Ana Menu ---\n");
        printf("1. Kamp alanina git.\n");
        printf("2. Sifahane.\n");
        printf("3. Hana git.\n");
        printf("4. Maceraya atil.\n");
        printf("5. Durumu goster.\n");
        printf("6. Oyundan cik.\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        if (secim == 6) {
            printf("Oyundan cikmak istediginize emin misiniz? (1: Evet, 0: Hayir): ");
            int onay;
            scanf("%d", &onay);
            if (onay == 1) {
                printf("Oyun sonlandiriliyor...\n");
                break;
            }
        } else {
            switch (secim) {
                case 1: kampAlani(); break;
                case 2: sifahane(); break;
                case 3: han(); break;
                case 4: macerayaAtil(); break;
                case 5: karakterDurumuGoster(); break;
                default: printf("Gecersiz secim! Tekrar deneyin.\n");
            }
        }
    }

    return 0;
}
