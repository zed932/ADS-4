// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;

  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == value) {
      if (arr[left] == arr[right]) {
        count += (right - left + 1) * (right - left) / 2;
        break;
      }
      int current_left = arr[left];
      int current_right = arr[right];
      int left_count = 0;
      int right_count = 0;

      while (left < len && arr[left] == current_left) {
        left++;
        left_count++;
      }
      while (right >= 0 && arr[right] == current_right) {
        right--;
        right_count++;
      }
      count += left_count * right_count;
    } else if (sum < value) {
      left++;
    } else {
      right--;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int target = value - arr[i];
    int low = i + 1;
    int high = len - 1;
    
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (arr[mid] == target) {
        count++;
        int left = mid - 1;
        while (left > i && arr[left] == target) {
          count++;
          left--;
        }
        int right = mid + 1;
        while (right < len && arr[right] == target) {
          count++;
          right++;
        }
        break;
      } else if (arr[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  return count;
}
