void Binary_Search(int arr[], int n, int k)
{
    // Initialize variables
    int low = 0;
    int mid = 0;
    int flag = 0;
    int high = n - 1;

    // Continue searching while search space exists
    while (low <= high)
    {
        // Find the middle index
        mid = (low + high) / 2;

        // If element is found
        if (arr[mid] == k)
        {
            flag = 1;
            break;
        }
        // Search in the left half
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        // Search in the right half
        else
        {
            low = mid + 1;
        }
    }

    // Print the result
    if (flag == 1)
        printf("%d number found at index %d", k, mid);
    else
        printf("Number not found");
}
