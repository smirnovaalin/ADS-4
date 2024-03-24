// Copyright 2021 NNTU-CS
void bubbleSort(int list[], int listLength){
  while (listLength--){
  bool swapped = false;
  for (int i = 0; i < listLength; i++){
    if (list[i] > list[i + 1]){
      int temp = list[i];
      list[i] = list[i + 1];
      list[i + 1] = temp;
      swapped = true;
    }
  }
    if (swapped == false)
      break;
  }
}

int countPairs1(int *arr, int len, int value) {
  bubbleSort(arr, len);
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  bubbleSort(arr, len);
  int count = 0;
  int max = len - 1;
  while (arr[max] >= value) {
    max--;
  }
  for (int i = 0; i < max; i++) {
    for (int j = i+1; j < max; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int cbinsearch(int *arr, int size, int value) {
  int count = 0;
  int left = 0, righ = size - 1;
  while (left <= righ) {
    int mid = (left+righ) / 2;
    if (arr[mid] == value) {
      int a = mid - 1;
      while (arr[mid] == value) {
        if (arr[mid] == value) {
          count++;
          mid++;
        }
      }
      while ( arr[a] == value) {
        if (arr[a] == value) {
          count++;
          --a;
        }
      }
      return count;
    } else if (arr[mid] < value) {
      left = mid + 1;
    } else {
      righ = mid - 1;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  bubbleSort(arr, len);
  int count = 0;
  for (int i = 0; i < len; i++) {
    int two = value - arr[i];
    count += cbinsearch(arr + i + 1, len - i - 1 , two);
  }
  return count;
}
