// Copyright 2021 NNTU-CS

int cbinsearch(int* arr, int size, int value) {
  int right_b = size;
  int left_b = 0;
  int middle = (left_b + right_b) / 2;
  if (((left_b >= middle) || (right_b <= middle)) && (arr[middle] != value))
    return 0;
  if (value < arr[middle])
    return cbinsearch(arr, middle, value);
  else
    if (value > arr[middle]) {
      return cbinsearch(arr + middle, right_b - middle + 1, value);
    }
    else {
      int i = 0;
      int ans = 0;
      while (value == arr[middle + i]) {
        i--;
      }
      i = i + 1;
      for (; value == arr[middle + i]; i++) {
        ans = ans + 1;
      }
      return ans;
    }
}

int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < (len - 1); i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[j] + arr[i] == value)
        count++;
    }
  }
  return count;
}

int countPairs2(int* arr, int len, int value) {
  int count = 0, k = len - 1;
  while (arr[k] > value) {
    len--;
    k--;
  }
  for (int i = 0; i < len; i++) {
    for (int j = len - 1; j >= i; j--) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }
  return count;
}

int countPairs3(int* arr, int len, int value) {
  int count = 0, tmp, k = len - 1;
  while (arr[k] > value) {
    len--;
    k--;
  }
  for (int i = 0; i < len; i++) {
    tmp = value - arr[i];
    count += cbinsearch(arr+i, len, tmp);
  }
  return count;
}
