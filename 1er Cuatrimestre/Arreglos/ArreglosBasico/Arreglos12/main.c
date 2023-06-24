#include <stdio.h>
#include <string.h>

void intercalar(char a[], char b[], char c[], int n);

int main() {
  char a[] = {'a', 'c', 'e', 'g', 'i'};
  char b[] = {'b', 'd', 'f', 'h', 'j'};
  char c[10];
  intercalar(a, b, c, 5);

  printf("Arreglo intercalado:\n");
  for (int i = 0; i < 10; i++) {
    printf("%c ", c[i]);
  }
  printf("\n");

  return 0;
}

void intercalar(char a[], char b[], char c[], int n) {
  int i = 0, j = 0, k = 0;

  while (i < n && j < n) {
    if (a[i] < b[j]) {
      c[k++] = a[i++];
    } else {
      c[k++] = b[j++];
    }
  }

  while (i < n) {
    c[k++] = a[i++];
  }

  while (j < n) {
    c[k++] = b[j++];
  }
}
