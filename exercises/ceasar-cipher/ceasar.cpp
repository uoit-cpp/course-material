#include <iostream>
#include <string>

using namespace std;

void shift_text(string& text, int shift)
{
  int n = text.length();
  for (int i=0; i<n; ++i)
  {
    char c = text[i];
 //   cout << (int) c << endl;
    c = 65 + (((c-65) + shift) % 26);
 //   cout << (int) c << endl;
    text[i] = c;
  }
}

int main()
{
  int shift;
  string plaintext;

  cout << "Enter shift +/- 26: ";
  cin >> shift;

  cout << "Enter plaintext message (A-Z only, no spaces): ";
  cin >> plaintext;

  int s = shift;
  if (shift < 0) s = 26 + s;  
  shift_text(plaintext, s);
  cout << "ciphertext: " << plaintext << endl;

  s = -shift;
  if (s < 0) s = 26 + s;
  shift_text(plaintext, s);
  cout << "plaintext: " << plaintext << endl;

  return 0;
}
