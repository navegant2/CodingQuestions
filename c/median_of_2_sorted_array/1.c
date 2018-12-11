#include<stdio.h>
#include<stdlib.h>


double median_of_2_sorted_arrays(int *array1, int *array2, int n1, int n2) {
  int is_even = 0;
    int total = n1+n2;
    int m_index = 0;
    int m_index1 = 0;
    int mid = (n1 + n2)/2;
    if (total % 2 == 0) { //even
        is_even = 1;
printf("is even\n");
    }
    int i = 0; int j = 0;
    int count = 0;

    while (count <= mid) {
printf("pass-%d\n", count);
        if (i < n1 && j < n2) {
            if (array1[i] < array2[j]) {
                m_index1 = m_index;
                m_index = array1[i];
                count++;
                i++;
            } else {
                m_index1 = m_index;
                m_index = array2[j];
                count++;
                j++;
            }
        } else if (i < n1) {
            m_index1 = m_index;
            m_index = array1[i];
            i++;
            count++;
        } else if (j < n2) {
            m_index1 = m_index;
            m_index = array2[j];
            j++;
            count++;
        }
    }
    if (is_even) {
        return ((double)m_index + (double)m_index1)/2;
    } else {
        return (double)m_index;
    }

}
main() {
    int n1;
    int n2;
    int i;
    int *array1;
    int *array2;

    scanf("%d %d", &n1, &n2);
    array1 = (int *)malloc(sizeof(int)*n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &array1[i]);
    }
    array2 = (int *)malloc(sizeof(int)*n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &array2[i]);
    }
    int result = median_of_2_sorted_arrays(array1, array2, n1, n2);
    printf("%d\n", result);

}
