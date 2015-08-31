
#include <stdio.h>
#include <assert.h>

static int is_sorted(int arr[], size_t arr_len) {
	assert(arr_len > 0);

	size_t i;
	for (i = 0; i < arr_len-1 && arr[i] <= arr[i+1]; i++)
		; /* Intentionally left blank */

	return i == arr_len-1;
}

static void swap(int arr[], size_t i, size_t j) {
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void slow_sort(int arr[], size_t arr_len) {
	if (arr_len == 0)
		return;

	size_t i;
	for (i = 0; i < arr_len; i++) {
		swap(arr, 0, i);
		slow_sort(arr+1, arr_len-1);
		if (is_sorted(arr, arr_len))
			return;
		swap(arr, 0, i);
	}
}

static void print_arr(int arr[], size_t arr_len) {
	printf("arr = [ ");
	if (arr_len > 0)
		printf("%d", arr[0]);
	size_t i;
	for (i = 1; i < arr_len; i++)
		printf(", %d", arr[i]);
	printf(" ];");
}

int main(void) {
	static int arr_buff[1024];
	size_t arr_len;

	printf("Enter array size, followed by the elements.\n");
	printf("> ");

	while (scanf("%zu", &arr_len) == 1) {
		size_t i;
		for (i = 0; i < arr_len; i++)
			scanf("%d", &arr_buff[i]);
		slow_sort(arr_buff, arr_len);
		print_arr(arr_buff, arr_len);
		printf("\n> ");
	}

	return 0;
}
