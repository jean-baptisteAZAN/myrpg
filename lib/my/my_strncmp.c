/*
** EPITECH PROJECT, 2022
** strncmp
** File description:
** yes
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    for (; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i > n; i++) {
        return (s1[i] - s2[i]);
    }
}
