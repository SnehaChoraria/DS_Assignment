#include <stdio.h>
#define SUB 10
#define MAIN 20

/* ───────────────────────── display ───────────────────────── */
void display(int a[], int n)
{
    if (n == 0)
    {
        printf("(empty)\n");
        return;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/* ───────────────────────── insert ────────────────────────── */
void insertEnd(int a[], int *n, int max)
{
    if (*n == max)
    {
        printf("Array full!\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &a[(*n)++]);
}

void insertBeg(int a[], int *n, int max)
{
    if (*n == max)
    {
        printf("Array full!\n");
        return;
    }
    for (int i = *n; i > 0; i--)
        a[i] = a[i - 1];
    printf("Enter value: ");
    scanf("%d", &a[0]);
    (*n)++;
}

void insertPos(int a[], int *n, int max, int p)
{
    if (*n == max || p < 0 || p > *n)
    {
        printf("Invalid!\n");
        return;
    }
    for (int i = *n; i > p; i--)
        a[i] = a[i - 1];
    printf("Enter value: ");
    scanf("%d", &a[p]);
    (*n)++;
}

/* ───────────────────────── delete ────────────────────────── */
void delEnd(int *n)
{
    if (*n > 0)
        (*n)--;
    else
        printf("Array empty!\n");
}

void delBeg(int a[], int *n)
{
    if (*n == 0)
    {
        printf("Array empty!\n");
        return;
    }
    for (int i = 0; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
}

void delPos(int a[], int *n, int p)
{
    if (*n == 0 || p < 0 || p >= *n)
    {
        printf("Invalid!\n");
        return;
    }
    for (int i = p; i < *n - 1; i++)
        a[i] = a[i + 1];
    (*n)--;
}

/* ───────────────────────── reverse ───────────────────────── */
void reverseTemp(int a[], int n)
{
    int t[n];
    for (int i = 0; i < n; i++)
        t[i] = a[n - 1 - i];
    printf("Reversed (temp): ");
    display(t, n);
}

void reverseIn(int a[], int n)
{
    int t;
    for (int i = 0; i < n / 2; i++)
    {
        t = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = t;
    }
}

/* ───────────────────────── copy / merge ──────────────────── */
/* Copy all elements of sub-array s[] into main array m[]     */
void copySub(int s[], int sn, int m[], int *mn)
{
    int copied = 0;
    for (int i = 0; i < sn && *mn < MAIN; i++, (*mn)++, copied++)
        m[*mn] = s[i];
    printf("%d element(s) copied to MainArray.\n", copied);
}

/*
 * Merge two arrays assuming both are sorted in DESCENDING order,
 * producing a merged result also in descending order.
 * Fix: comparison was backwards in the original (produced ascending order).
 */
void mergeDesc(int a[], int n1, int b[], int n2)
{
    int c[n1 + n2], i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
        c[k++] = (a[i] >= b[j]) ? a[i++] : b[j++]; /* >= keeps descending */
    while (i < n1)
        c[k++] = a[i++];
    while (j < n2)
        c[k++] = b[j++];
    printf("Merged (descending): ");
    display(c, k);
}

/* ───────────────────────── sum ───────────────────────────── */
int sumIter(int a[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += a[i];
    return s;
}

int sumRec(int a[], int n)
{
    if (n == 0)
        return 0;
    return a[n - 1] + sumRec(a, n - 1);
}

/* ───────────────────────── search ───────────────────────── */
void search(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (a[i] == x)
        {
            printf("Found at index %d\n", i);
            return;
        }
    printf("Not found\n");
}

/* ───────────────────────── separate ─────────────────────── */
void oddEven(int a[], int n)
{
    printf("Even: ");
    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            printf("%d ", a[i]);
    printf("\nOdd:  ");
    for (int i = 0; i < n; i++)
        if (a[i] % 2 != 0)
            printf("%d ", a[i]);
    printf("\n");
}

void posNeg(int a[], int n)
{
    printf("Positive: ");
    for (int i = 0; i < n; i++)
        if (a[i] >= 0)
            printf("%d ", a[i]);
    printf("\nNegative: ");
    for (int i = 0; i < n; i++)
        if (a[i] < 0)
            printf("%d ", a[i]);
    printf("\n");
}

/* ───────────────────────── to fill sub-array ────────── */
void fillArray(int a[], int *n, int max)
{
    printf("How many elements (max %d)? ", max);
    int cnt;
    scanf("%d", &cnt);
    if (cnt > max)
        cnt = max;
    printf("Enter %d elements: ", cnt);
    for (int i = 0; i < cnt; i++)
        scanf("%d", &a[i]);
    *n = cnt;
}

/* ═══════════════════════════ main ═══════════════════════════ */
int main()
{
    int SubArray1[SUB], SubArray2[SUB], MainArray[MAIN];
    int s1 = 0, s2 = 0, m = 0, ch, p, x;

    while (1)
    {
        printf("\n========= MENU =========\n");
        printf(" 1  Insert at End\n");
        printf(" 2  Insert at Beginning\n");
        printf(" 3  Insert at Position\n");
        printf(" 4  Delete from End\n");
        printf(" 5  Delete from Beginning\n");
        printf(" 6  Delete from Position\n");
        printf(" 7  Reverse (temp array)\n");
        printf(" 8  Reverse (in-place)\n");
        printf(" 9  Sum (iterative + recursive)\n");
        printf("10  Search\n");
        printf("11  Separate (odd/even & pos/neg)\n");
        printf("12  Fill SubArray1\n");
        printf("13  Fill SubArray2\n");
        printf("14  Copy SubArray1 -> MainArray\n");
        printf("15  Copy SubArray2 -> MainArray\n");
        printf("16  Merge SubArray1 & SubArray2 (desc)\n");
        printf(" 0  Exit\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        /* ── insert ── */
        case 1:
            insertEnd(MainArray, &m, MAIN);
            break;
        case 2:
            insertBeg(MainArray, &m, MAIN);
            break;
        case 3:
            printf("Position: ");
            scanf("%d", &p);
            insertPos(MainArray, &m, MAIN, p);
            break;

        /* ── delete ── */
        case 4:
            delEnd(&m);
            break;
        case 5:
            delBeg(MainArray, &m);
            break;
        case 6:
            printf("Position: ");
            scanf("%d", &p);
            delPos(MainArray, &m, p);
            break;

        /* ── reverse ── */
        case 7:
            reverseTemp(MainArray, m);
            continue; /* already printed */
        case 8:
            reverseIn(MainArray, m);
            break;

        /* ── sum ── */
        case 9:
            printf("Iterative sum = %d\n", sumIter(MainArray, m));
            printf("Recursive sum = %d\n", sumRec(MainArray, m));
            continue;

        /* ── search ── */
        case 10:
            printf("Search value: ");
            scanf("%d", &x);
            search(MainArray, m, x);
            continue;

        /* ── separate ── */
        case 11:
            oddEven(MainArray, m);
            posNeg(MainArray, m);
            continue;

        /* ── sub-array ops ── */
        case 12:
            fillArray(SubArray1, &s1, SUB);
            printf("SubArray1: ");
            display(SubArray1, s1);
            continue;
        case 13:
            fillArray(SubArray2, &s2, SUB);
            printf("SubArray2: ");
            display(SubArray2, s2);
            continue;

        case 14:
            copySub(SubArray1, s1, MainArray, &m);
            break;
        case 15:
            copySub(SubArray2, s2, MainArray, &m);
            break;

        case 16:
            mergeDesc(SubArray1, s1, SubArray2, s2);
            continue;

        case 0:
            return 0;

        default:
            printf("Invalid choice.\n");
            continue;
        }

        printf("MainArray: ");
        display(MainArray, m);
    }
}