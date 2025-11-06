#include &lt;stdio.h&gt;
void selectionSort(int arr[], int n) {
int i, j, minIndex, temp;
for (i = 0; i &lt; n - 1; i++) {
minIndex = i;
for (j = i + 1; j &lt; n; j++) {
if (arr[j] &lt; arr[minIndex])
minIndex = j;
}
// Swap
temp = arr[i];
arr[i] = arr[minIndex];
arr[minIndex] = temp;
}
}
void printArray(int arr[], int n) {
for (int i = 0; i &lt; n; i++)
printf(&quot;%d &quot;, arr[i]);
printf(&quot;\n&quot;);
}
int main() {
int arr[] = {64, 25, 12, 22, 11};
int n = sizeof(arr)/sizeof(arr[0]);

printf(&quot;Original array: &quot;);
printArray(arr, n);
selectionSort(arr, n);
printf(&quot;Sorted array (Selection Sort): &quot;);
printArray(arr, n);
return 0;
}
