int linearSearch(int arr[], int n, int key) {
int i; // declare here
for (i = 0; i &lt; n; i++) {
if (arr[i] == key)
return i;
}
return -1;
}
int main() {
int arr[] = {5, 3, 8, 6, 2};
int n = sizeof(arr) / sizeof(arr[0]);
int target = 2;
int result = linearSearch(arr, n, target);
if (result != -1) {
printf(&quot;Element %d found at index %d\n&quot;, target, result);
} else {
printf(&quot;Element %d not found\n&quot;, target);
}
return 0;
}
