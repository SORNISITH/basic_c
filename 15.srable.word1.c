#include <ctype.h>
#include <stdio.h>

int check_string_return_face(char s[], char s2[], int face_value);
int main(int argc, char* argv[])

{
    char face_value_1[11] = "AEILNORSTU";
    char face_value_2[3] = "DG";
    char face_value_3[5] = "BCMP";
    char face_value_4[6] = "FHVWY";
    char face_value_5[2] = "K";
    char face_value_8[3] = "JX";
    char face_value_10[3] = "QZ";
    char word[128] = { "0" };
    int index = 0;
    printf("Enter Word : ");
    scanf("%s", word);
    int sum = 0;
    while (word[index] != '\0') {
        word[index] = toupper(word[index]);

        index++;
    }

    printf("%s\n", word);
    sum += check_string_return_face(word, face_value_1, 1);
    sum += check_string_return_face(word, face_value_2, 2);
    sum += check_string_return_face(word, face_value_3, 3);
    sum += check_string_return_face(word, face_value_4, 4);
    sum += check_string_return_face(word, face_value_5, 5);
    sum += check_string_return_face(word, face_value_8, 8);
    sum += check_string_return_face(word, face_value_10, 10);

    printf("Scrable Value : %d", sum);
    return 0;
}

int check_string_return_face(char s[], char s2[], int face_value)
{
    int sum = 0;
    int index = 0;
    int kndex = 0;
    while (s[index] != '\0') {
        while (s2[kndex] != '\0') {
            if (s[index] == s2[kndex]) {
                sum += face_value;
                kndex = 0;
                break;
            } else {
                kndex++;
            }
        }
        index++;
        kndex = 0;
    }
    return sum;
};
