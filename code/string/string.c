// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* implementarea strcpy din laboratorul 1, software-stack */
	char *destination_ptr;
	for (destination_ptr = destination; *source != '\0'; source++, destination_ptr++) {
		*destination_ptr = *source;
	}
	*destination_ptr = *source;
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *destination_ptr = destination;
	/* parcurg pana la len si copiez */
	for (size_t i = 0; i < len; i++) {
		*destination_ptr = *source;
		destination_ptr++;
		source++;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	char *destination_ptr = destination;
	/* ma pozitionez la sfarsitul stringului destinatie */
	for (;*destination_ptr != '\0'; destination_ptr++) {}
	const char *source_ptr;
	/* parcurg sirul sursa si il copiez in sirul destinatie */
	for (source_ptr = source; *source_ptr != '\0'; destination_ptr++, source_ptr++) {
		*destination_ptr = *source_ptr;
	}
	*destination_ptr = *source_ptr;
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *destination_ptr = destination;
	/* ma pozitionez la sfarsitul sirului destinatie */
	for (; *destination_ptr != '\0'; destination_ptr++) {}
	const char *source_ptr = source;
	/* parcurg pana la len si copiez sirul sursa in sirul destinatie */
	for (size_t i = 0; i < len; i++) {
		if (*source_ptr != '\0') {
			*destination_ptr = *source_ptr;
			destination_ptr++;
			source_ptr++;
		}
	}
	*destination_ptr = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* parcurg concomitent cele doua string-uri si le compar caracter cu caracter */
	for (; *str1 != '\0' && *str2 != '\0'; str1++, str2++) {
		if (*str1 > *str2) {
			return 1;
		} else if (*str1 < *str2) {
			return -1;
		}
	}
	/* verific daca str1 este mai lung decat str2 */
	if (*str1 != '\0' && *str2 == '\0') {
		return 1;
	}
	/* verific daca str1 este mai scurt decat str2 */
	if (*str1 == '\0' && *str2 != '\0') {
		return -1;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* parcurg sirurile pana la lungimea len si le compar caracter cu caracter */
	for (size_t i = 0; i < len; i++) {
		if (*str1 > *str2) {
			return 1;
		} else if (*str1 < *str2) {
			return -1;
		}
		str1++;
		str2++;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* parcurg sirul cu ajutorul unui pointer si compar fiecare dintre caracterele sirului cu c */
	const char *str_ptr;
	for (str_ptr = str; *str_ptr != '\0'; str_ptr++) {
		if (*str_ptr == c) {
			return (char *) str_ptr;
		}
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	const char *str_ptr;       // pointerul cu care parcurg sirul
	const char *r_str = NULL;  // pointerul in care retin aparitia cea mai din dreapta a caracterului c
	/* parcurg sirul si verific daca caracterul curent este c, caz in care actualizez pozitia cea mai din dreapta */
	for (str_ptr = str; *str_ptr != '\0'; str_ptr++) {
		if (*str_ptr == c) {
			r_str = str_ptr;
		}
	}
	/* returnez pozitia celui mai din dreapta caracter c */
	if (r_str != NULL) {
		return (char *) r_str;
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
	/* parcurg string-ul in care caut string-ul needle */
	for (; *haystack != '\0'; haystack++) {
		/* declar un pointer cu ajutorul caruia parcurg string-ul needle */
		const char *haystack_ptr = haystack;
		const char *needle_ptr = needle;
		/* cat timp sirul needle se gaseste in sirul haystack, parcurg concomitent cele doua siruri */
		for (; *haystack_ptr == *needle_ptr && *haystack_ptr != '\0' && *needle_ptr != '\0'; haystack_ptr++, needle_ptr++) {}
		/* daca am ajuns la sfarsitul stringului cautat, atunci retunez adresa de inceput a acestuia in sirul haystack*/
		if (*needle_ptr == '\0') {
			return (char *) haystack;
		}
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
/* parcurg string-ul in care caut string-ul needle */
	const char *needle_start = NULL;
	for (; *haystack != '\0'; haystack++) {
		/* declar un pointer cu ajutorul caruia parcurg string-ul needle */
		const char *haystack_ptr = haystack;
		const char *needle_ptr = needle;
		/* cat timp sirul needle se gaseste in sirul haystack, parcurg concomitent cele doua siruri */
		for (; *haystack_ptr == *needle_ptr && *haystack_ptr != '\0' && *needle_ptr != '\0'; haystack_ptr++, needle_ptr++) {}
		/* actualizez pozitia de inceput a sirului needle in sirul haystack */
		if (*needle_ptr == '\0') {
			needle_start = haystack;
		}
	}
	/* returnez adresa cea mai din dreapta a sirului needle in sirul haystack */
	if (needle_start != NULL) {
		return (char *) needle_start;
	}
	return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* fac cast la tipul (char *) */
	char *destination_ptr = (char *)destination;
	char *source_ptr = (char *)source;
	/* aplic algoritmul redactat la functia strcpy */
	for (size_t i = 0; i < num; i ++) {
		*destination_ptr = *source_ptr;
		destination_ptr++;
		source_ptr++;
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* fac cast la tipul (char *) */
	char *destination_ptr = (char *)destination;
	char *source_ptr = (char *)source;
	char auxiliary[10000];    // vectorul auxiliar pe care il folosesc pe post de buffer
	/* copiez caracterele sirului sursa in buffer */
	for (size_t i = 0; i < num; i ++) {
		auxiliary[i] = source_ptr[i];
	}
	/* copiez caracterele din buffer in sirul destinatie */
	for (size_t i = 0; i < num; i ++) {
		destination_ptr[i] = auxiliary[i];
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* fac cast la tipul (char *) */
	char *ptr1_ptr = (char *)ptr1;
	char *ptr2_ptr = (char *)ptr2;
	/* aplic algoritmul redactat la functia strcmp */
	for (size_t i = 0; i < num; i++) {
		if (*ptr1_ptr > *ptr2_ptr) {
			return 1;
		} else if (*ptr1_ptr < *ptr2_ptr) {
			return -1;
		}
		ptr1_ptr++;
		ptr2_ptr++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* fac cast la tipul (char *) */
	char *source_ptr = (char *)source;
	/* parcurg sursa si setez fiecare octet la valoarea value */
	for (size_t i = 0; i < num; i++) {
		*source_ptr = value;
		source_ptr++;
	}
	return source;
}
