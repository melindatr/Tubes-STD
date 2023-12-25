#include "pasien.h"

void createList(List_pasien &L) {
    first(L) = NULL;
    last(L) = NULL;
}

address_pasien alokasi(infotype_pasien x) {
    address_pasien P = new elmlist_pasien;
    x.id = 0;
    x.status = false;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void tambahPasien(List_pasien &L) {
    int n, i;
    infotype_pasien xP;
    address_pasien P, Q;
    cout << "Jumlah data pasien yang ditambahkan: ";
    cin >> n;
    cout << "Masukan data pasien: Nama dan Umur" << endl;
    for (i = 1; i <= n; i++) {
        cin >> xP.nama >> xP.umur;
        Q = findElm(L, xP.nama);
        if (Q == NULL) {
            P = alokasi(xP);
            insertLast(L, P);
        } else {
            while (Q != NULL) {
                cout << "Terdapat pasien dengan nama yang sama persis, mohon input ulang nama dan umur" << endl;
                cin >> xP.nama >> xP.umur;
                Q = findElm(L, xP.nama);
            }
            P = alokasi(xP);
            insertLast(L, P);
        }
    }
}

void insertFirst(List_pasien &L, address_pasien P) {
    if(first(L) == NULL) {
        last(L) = P;
        first(L) = P;
    } else {
        next(P) = first(L);
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List_pasien &L, address_pasien P) {
    if(first(L) == NULL) {
        info(P).id = 1;
        last(L) = P;
        first(L) = P;
    } else {
        info(P).id = info(last(L)).id + 1;
        prev(P) = last(L);
        next(last(L)) = P;
        last(L) = P;
    }
}

void printInfo(List_pasien L) {
    /**
    * FS : menampilkan info seluruh elemen list L
    */
    string input;
    address_pasien P = first(L);
    printf("---------------------------------\n");
    printf("| ID\t| NAMA\t\t| UMUR\t|\n");
    printf("---------------------------------\n");
    if(first(L)!=NULL) {
        do {
            cout << "| " << info(P).id << "\t| " << info(P).nama << "\t\t| " << info(P).umur << "\t| " << endl;
            P = next(P);
        } while((P)!=NULL);
    }
    printf("---------------------------------\n");
    cout << endl;
    cout << "Tekan apapun untuk kembali" << endl;
    cin >> input;
}


address_pasien findElm(List_pasien L, string nama) {
    address_pasien P = first(L);
    while(P != NULL) {
        if(info(P).nama == nama) {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void insertAfter(address_pasien &Prec, address_pasien P) {
    prev(next(Prec)) = P;
    next(P) = next(Prec);
    prev(P) = Prec;
    next(Prec) = P;
}

void deleteElm(List_pasien &L, address_pasien prec, address_pasien &p) {
    if (prec == first(L)) {
        p = prec;
        first(L) = next(p);
        prev(first(L)) = NULL;
        next(p) = NULL;
    } else if (prec == last(L)) {
        p = prec;
        last(L) = prev(p);
        next(last(L)) = NULL;
        prev(p) = NULL;
    } else {
        address_pasien Q;
        p = prec;
        Q = prev(prec);
        next(Q) = next(p);
        prev(next(Q)) = Q;
        next(p) = NULL;
        prev(p) = NULL;
    }
}

int countPasien(List_pasien L) {
    address_pasien p;

    int i = 0;

    p = first(L);
    while (p != NULL) {
        i++;
        p = next(p);
    }

    return i;
}

void cariDataPasien(List_pasien L) {
    string nama, opsi;
    address_pasien P;
    cout << "Masukan nama pasien: ";
    cin >> nama;

    P = findElm(L, nama);
    if (P == NULL) {
        cout << "Nama pasien tidak ditemukan" << endl;
        cout << "Cari lagi? (y/n) ";
        cin >> opsi;
        if (opsi == "y") {
            cariDataPasien(L);
        }
    } else {
        printf("---------------------------------\n");
        printf("| ID\t| NAMA\t\t| UMUR\t|\n");
        printf("---------------------------------\n");
        cout << "| " << info(P).id << "\t| " << info(P).nama << "\t\t| " << info(P).umur << "\t| " << endl;
        printf("---------------------------------\n");
        cout << "Tekan apapun untuk kembali" << endl;
        cin >> opsi;
    }
}

void menuPasien(int x){
    List_pasien L;
    address_pasien prec, p;
    string kode;
    if (x == 1) {
        tambahPasien(L);
    } else if (x == 2) {
        //deleteElm(L, prec, p);
    } else if (x == 3) {
        //kunjungan
    } else if (x == 4) {
        //findElm(L,kode);
    } else if (x == 5) {
        //jadwal
    } else if (x == 6) {
        countPasien(L);
    } else if (x == 7) {
        printInfo(L);
    } else {
        //start();
    }
}
