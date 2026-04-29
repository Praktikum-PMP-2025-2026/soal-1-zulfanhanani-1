/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 3 - STRUCTURES AND DYNAMIC ARRAYS
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : Zulfan Hanani (13224105)
 *   Nama File           : soal1Rabu.c
 *   Deskripsi           : Soal 1 - Arsip Artefak Terkategori
 *                         Membuat urutan artefak
 * 
 */


#include <stdio.h>
#include <string.h>

typedef struct Artefak{
   char nama[20];
   char kategori[20];
   int tahun;
   int nilai;
}Artefak;

void nuker(Artefak *artefak1, Artefak *artefak2){
   Artefak temp = *artefak1;
   *artefak1 = *artefak2;
   *artefak2 = temp;
}

int main() {
   int n;
   scanf("%d", &n);
   Artefak artefak[n];

   for (int i = 0; i < n; i++){
      scanf("%s", artefak[i].nama);
      scanf("%s", artefak[i].kategori);
      scanf("%d", &artefak[i].tahun);
      scanf("%d", &artefak[i].nilai);
   }
   
   for (int i = 0; i < n - 1; i++){
      for (int j = 0; j < n - i - 1; j++){
         if (strcmp(artefak[j+1].kategori, artefak[j].kategori) < 0){
            nuker(&artefak[j+1], &artefak[j]);
         }else if (strcmp(artefak[j].kategori, artefak[j+1].kategori) == 0){
            if (artefak[j+1].tahun < artefak[j].tahun){
               nuker(&artefak[j+1], &artefak[j]);
            }else if (artefak[j].tahun == artefak[j+1].tahun){
               if (artefak[j+1].nilai > artefak[j].nilai){
                  nuker(&artefak[j+1], &artefak[j]);
               }else if (artefak[j].nilai == artefak[j+1].nilai){
                  if (strcmp(artefak[j].nama, artefak[j+1].nama) > 0){
                     nuker(&artefak[j+1], &artefak[j]);
                  }
               }
            }
         }
      }
   }
   
   for (int i = 0; i < n; i++){
      printf("%s %s %d %d\n", artefak[i].nama, artefak[i].kategori, artefak[i].tahun, artefak[i].nilai);
   }
   
   return 0;
}
 
