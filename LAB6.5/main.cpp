#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int *intersection(int arr1[], int arr2[], int n1, int n2, int &n3) {

    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);

    int i = 0, j = 0, k = 0;
    int *res = new int[min(n1, n2)];

    while (i < n1 && j < n2) {

        if (arr1[i] < arr2[j]) {
            i++;
        } else if (arr1[i] > arr2[j]) {
            j++;
        } else {
            res[k++] = arr1[i++];
            j++;
        }
    }
    n3 = k;

    return res;
}

bool isPalindrome(string str) {

    int n = str.length();

    for (int i = 0; i < n / 2; i++) {

        if (str[i] != str[n - i - 1]) {
            return false;
        }
    }

    return true;
}

void sieve_of_eratosthenes(int arr[], int n) {

    int max_elem = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] > max_elem) {
            max_elem = arr[i];
        }
    }

    bool prime[max_elem + 1];

    for (int i = 0; i <= max_elem; i++) {
        prime[i] = true;
    }

    prime[0] = false;
    prime[1] = false;

    for (int p = 2; p * p <= max_elem; p++) {

        if (prime[p]) {
            for (int i = p * 2; i <= max_elem; i += p) {
                prime[i] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (prime[arr[i]]) {
            cout << arr[i] << " ";
        }
    }
}


list<string> Anagrams(string word, const list<string> &word_list) {

    list<string> anagrams_list;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    sort(word.begin(), word.end());

    for (auto &it: word_list) {

        string sorted_word = it;
        transform(sorted_word.begin(), sorted_word.end(), sorted_word.begin(), ::tolower);
        sort(sorted_word.begin(), sorted_word.end());

        if (sorted_word == word) {
            anagrams_list.push_back(it);
        }
    }

    return anagrams_list;
}

int main() {

    int n1, n2;
    cout << "Enter the size of first list: ";
    cin >> n1;

    int arr1[n1];
    cout << "Enter the elements of first list: ";

    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the size of second list: ";
    cin >> n2;

    int arr2[n2];
    cout << "Enter the elements of second list: ";

    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    int n3 = 0;
    int *res = intersection(arr1, arr2, n1, n2, n3);

    cout << "Intersection of the two lists: ";

    for (int i = 0; i < n3; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    delete[] res;

    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    string arr[n];
    cout << "Enter the strings: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    string palindromes[n];
    int count = 0;

    for (int i = 0; i < n; i++) {

        if (isPalindrome(arr[i])) {
            palindromes[count++] = arr[i];
        }
    }

    cout << "Palindromes in the list: ";

    for (int i = 0; i < count; i++) {
        cout << palindromes[i] << " ";
    }

    cout << endl;

    int m;
    cout << "Enter the size of the array: ";
    cin >> m;

    int _arr[m];
    cout << "Enter " << m << " integers: ";

    for (int i = 0; i < m; i++) {
        cin >> _arr[i];
    }

    cout << "Prime numbers in the array: ";
    sieve_of_eratosthenes(_arr, m);

    cout << endl;

    string word = "listen";
    list<string> word_list = {"enlists", "google", "inlets", "banana"};
    list<string> anagrams_list = Anagrams(word, word_list);
    cout << "Anagrams: ";

    for (auto &it: anagrams_list) {
        cout << it << " | ";
    }

    return 0;
}