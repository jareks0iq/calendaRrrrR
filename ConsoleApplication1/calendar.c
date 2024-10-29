#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>
int vr(int something[]) {
	int ch, k = 0;
	int date[6] = { -1, -1, -1, -1, -1, -1 };
	printf("Введите время: ");
	while (date[5] == -1) {
		ch = getch();
		if (ch != 8) {
			if (ch == 58) {
				if (k == 1 || k == 3) {
					date[k] = date[k - 1];
					date[k - 1] = 0;
					k++;
					system("cls");
					printf("Введите время: ");
					for (int i = 0; i < 6; i++) {
						if (date[i] != -1) {
							printf("%d", date[i]);
							if (i == 1 || i == 3) {
								printf(":");
							}
						}
						else { break; }
					}
				}

			}
			else if (ch == 13 && k == 5) {
				date[5] = date[4];
				date[4] = 0;
			}
			else {
				if (isdigit(ch)) {
					sscanf_s(&ch, "%d", &date[k]);
					k++;
					system("cls");
					printf("Введите время: ");
					for (int i = 0; i < 6; i++) {
						if (date[i] != -1) {
							printf("%d", date[i]);
							if (i == 1 || i == 3) {
								printf(":");
							}
						}
						else { break; }
					}
				}
				else {
					system("cls");
					printf("Введите время: ");
					for (int i = 0; i < 6; i++) {
						if (date[i] != -1) {
							printf("%d", date[i]);
							if (i == 1 || i == 3) {
								printf(":");
							}
						}
						else { break; }
					}
				}
			}
		}
		else if (ch == 8) {
			if (k > 0) { date[k - 1] = -1; }
			else { date[0] = -1; }
			if (k > 0) { k--; }
			else { k = 0; }
			system("cls");
			printf("Введите время: ");
			for (int i = 0; i < 6; i++) {
				if (date[i] != -1) {
					printf("%d", date[i]);
					if (i == 1 || i == 3) {
						printf(":");
					}
				}
				else { break; }
			}
		}
	}
	int hours, minutes, seconds;
	hours = date[0] * 10 + date[1];
	minutes = date[2] * 10 + date[3];
	seconds = date[4] * 10 + date[5];
	if (hours < 24 && minutes < 60 && seconds < 60) {
		something[0] = hours;
		something[1] = minutes;
		something[2] = seconds;
		return 1;
	}
	else {
		return 0;
	}
}
int da(int something[]) {
	int ch, k = 0;
	int date[] = { -1, -1, -1, -1, -1, -1, -1, -1 };
	printf("Введите дату от 1930 до 2030-го года включительно: ");
	while (date[7] == -1) {
		ch = getch();
		if (ch != 8) {
			if (ch == 46 || ch == 47) {
				if (k == 1 || k == 3) {
					date[k] = date[k - 1];
					date[k - 1] = 0;
					k++;
					system("cls");
					printf("Введите дату от 1930 до 2030-го года включительно: ");
					for (int i = 0; i < 8; i++) {
						if (date[i] != -1) {
							printf("%d", date[i]);
							if (i == 1 || i == 3) {
								printf(".");
							}
						}
						else { break; }
					}
				}

			}
			else {
				if (isdigit(ch)) {
					sscanf_s(&ch, "%d", &date[k]);
					k++;
					system("cls");
					printf("Введите дату от 1930 до 2030-го года включительно: ");
					for (int i = 0; i < 8; i++) {
						if (date[i] != -1) {
							printf("%d", date[i]);
							if (i == 1 || i == 3) {
								printf(".");
							}
						}
						else { break; }
					}
				}
				else {
					system("cls");
					printf("Введите дату от 1930 до 2030-го года включительно: ");
					for (int i = 0; i < 8; i++) {
						if (date[i] != -1) {
							printf("%d", date[i]);
							if (i == 1 || i == 3) {
								printf(".");
							}
						}
						else { break; }
					}
				}
			}
		}
		else if (ch == 8) {
			if (k > 0) { date[k - 1] = -1; }
			else { date[0] = -1; }
			if (k > 0) { k--; }
			else { k = 0; }
			system("cls");
			printf("Введите дату от 1930 до 2030-го года включительно: ");
			for (int i = 0; i < 8; i++) {
				if (date[i] != -1) {
					printf("%d", date[i]);
					if (i == 1 || i == 3) {
						printf(".");
					}
				}
				else { break; }
			}
		}
	}
	int day, month, year;
	day = date[0] * 10 + date[1];
	month = date[2] * 10 + date[3];
	year = date[4] * 1000 + date[5] * 100 + date[6] * 10 + date[7];
	int dmax = 0;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		dmax = 31;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		dmax = 30;
	}
	else if (month == 2) {
		if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0)) {
			dmax = 29;
		}
		else {
			dmax = 28;
		}
	}
	if ((day > 0 && day <= dmax) && (month > 0 && month <= 12) && (year > 1929 && year < 2031)) {
		something[0] = day;
		something[1] = month;
		something[2] = year;
		return 1;
	}
	else {
		return 0;
	}
}
int god[] = { 1,4,4,0,2,5,0,3,6,1,4,6 };
int notgod[] = { 0,3,4,0,2,5,0,3,6,1,4,6 };
int den(int a) {
	if (a == 0) { printf("Суббота \n"); }
	else if (a == 1) { printf("Воскресенье \n"); }
	else if (a == 2) { printf("Понедельник \n"); }
	else if (a == 3) {printf("Вторник \n");}
	else if (a == 4) { printf("Среда \n"); }
	else if (a == 5) { printf("Четверг \n"); }
	else if (a == 6) { printf("Пятница \n"); }
}
int ned(int d, int m, int y) {
	int denned = 0, kodm = 0, kodg = 0;
	if (y % 4 == 0 || (y % 100 == 0 && y % 400 == 0)) {
		kodm = notgod[m - 1];
	}
	else {
		kodm = god[m - 1];
	}
	if (2000 <= y && y <= 2099) { kodg = (6 + y % 100 + ((y % 100) / 4)) % 7; return (d + kodm + kodg) % 7; }
	else if (1900 <= y && y <= 1999) { kodg = (y % 100 + ((y % 100) / 4)) % 7; return (d + kodm + kodg) % 7;}
}
int date(int ddni, int d, int m, int y, int arr[]) {
	int provdate = 0;
	if (ddni >= 0) {
		while (ddni > 0) {
			if (ddni > 31) {
				if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10) {
					if (d != 0) {
						ddni = ddni - 31 + d;
						m++;
						d = 0;
					}
					else {
						ddni = ddni - 31;
						m++;
					}
				}
				else if (m == 2) {
					if (y % 4 == 0 || (y % 100 == 0 && y % 400 == 0)) {
						if (d != 0) {
							ddni = ddni - 29 + d;
							m++;
							d = 0;
						}
						else {
							ddni = ddni - 29;
							m++;
						}
					}
					else {
						if (d != 0) {
							ddni = ddni - 28 + d;
							m++;
							d = 0;
						}
						else {
							ddni = ddni - 28;
							m++;
						}
					}
				}
				else if (m == 4 || m == 6 || m == 9 || m == 11) {
					if (d != 0) {
						ddni = ddni - 30 + d;
						m++;
						d = 0;
					}
					else {
						ddni = ddni - 30;
						m++;
					}
				}
				else if (m == 12) {
					if (d != 0) {
						ddni = ddni - 31 + d;
						y++;
						m = 1;
						d = 0;
					}
					else {
						ddni = ddni - 31;
						y++;
						m = 1;
					}
				}
				else { provdate = -1; ddni = 0; }
			}
			else if (ddni <= 31) {
				if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10) {
					if (d != 0) {
						if (31 - d >= ddni) {
							d = d + ddni;
							ddni = 0;
						}
						else {
							ddni = ddni - 31 + d;
							d = ddni;
							ddni = 0;
							m++;
						}
					}
					else {
						d = ddni;
						ddni = 0;
					}
				}
				else if (m == 2) {
					if (d != 0) {
						if (y % 4 == 0 || (y % 100 == 0 && y % 400 == 0)) {
							if (29 - d >= ddni) {
								d = d + ddni;
								ddni = 0;
							}
							else {
								ddni = ddni - 29 + d;
								d = ddni;
								ddni = 0;
								m++;
							}
						}
						else {
							if (28 - d >= ddni) {
								d = d + ddni;
								ddni = 0;
							}
							else {
								ddni = ddni - 28 + d;
								d = ddni;
								ddni = 0;
								m++;
							}
						}
					}
					else {
						if (y % 4 == 0 || (y % 100 == 0 && y % 400 == 0)) {
							if (ddni == 31) {
								d = 2;
								m++;
								ddni = 0;
							}
							else if (ddni == 30) {
								d = 1;
								m++;
								ddni = 0;
							}
							else {
								d = ddni;
								ddni = 0;
							}
						}
						else {
							if (ddni == 31) {
								d = 3;
								m++;
								ddni = 0;
							}
							else if (ddni == 30) {
								d = 2;
								m++;
								ddni = 0;
							}
							else if (ddni == 29) {
								d = 1;
								m++;
								ddni = 0;
							}
							else {
								d = ddni;
								ddni = 0;
							}
						}
					}
				}
				else if (m == 4 || m == 6 || m == 9 || m == 11) {
					if (d != 0) {
						if (30 - d >= ddni) {
							d = d + ddni;
							ddni = 0;
						}
						else {
							ddni = ddni - 30 + d;
							d = ddni;
							ddni = 0;
							m++;
						}
					}
					else {
						if (ddni == 31) {
							d = 1;
							m++;
							ddni = 0;
						}
						else {
							d = ddni;
							ddni = 0;
						}
					}
				}
				else if (m == 12) {
					if (d != 0) {
						if (31 - d >= ddni) {
							d = d + ddni;
							ddni = 0;
						}
						else {
							ddni = ddni - 31 + d;
							d = ddni;
							ddni = 0;
							m = 1;
							y++;
						}
					}
					else {
						d = ddni;
						ddni = 0;
					}
				}
				else { provdate = -1; ddni = 0;}
			}
		}
	}
	else {
		while (ddni < 0) {
			if (abs(ddni) > 31) {
				if (m == 1) {
					if (d != 0) {
						ddni = ddni + d;
						m = 12;
						y--;
						d = 0;
					}
					else {
						ddni = ddni + 31;
						m = 12;
						y--;
					}
				}
				else if (m == 2) {
					if (y % 4 == 0 || (y % 100 == 0 && y % 400 == 0)) {
						if (d != 0) {
							ddni = ddni + d;
							m--;
							d = 0;
						}
						else {
							ddni = ddni + 29;
							m--;
						}
					}
					else {
						if (d != 0) {
							ddni = ddni + d;
							m--;
							d = 0;
						}
						else {
							ddni = ddni + 28;
							m--;
						}
					}
				}
				else if (m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
					if (d != 0) {
						ddni = ddni + d;
						d = 0;
						m--;
					}
					else {
						ddni = ddni + 31;
						m--;
					}
				}
				else if (m == 4 || m == 6 || m == 9 || m == 11) {
					if (d != 0) {
						ddni = ddni + d;
						m--;
						d = 0;
					}
					else {
						ddni = ddni + 30;
						m--;
					}
				}
				else { provdate = -1; ddni = 0; }
			}
			else {
				if (m == 1) {
					if (d != 0) {
						if (d > abs(ddni)) {
							d = d + ddni;
							ddni = 0;
						}
						else {
							ddni = ddni + d;
							d = 31 + ddni;
							m = 12;
							y--;
							ddni = 0;
						}
					}
					else {
						if (abs(ddni) == 31) {
							d = 31;
							m = 12;
							y--;
							ddni = 0;
						}
						else {
							d = 31 + ddni;
							ddni = 0;
						}
					}
				}
				else if (m == 2) {
					if (d != 0) {
						if (d > abs(ddni)) {
							d = d + ddni;
							ddni = 0;
						}
						else {
							ddni = ddni + d;
							d = 31 + ddni;
							m--;
							ddni = 0;
						}
					}
					else {
						if (y % 4 == 0 || (y % 100 == 0 && y % 400 == 0)) {
							if (abs(ddni) == 31) {
								d = 31 - 2;
								m--;
								ddni = 0;
							}
							else if (abs(ddni) == 30) {
								d = 31 - 1;
								m--;
								ddni = 0;
							}
							else if (abs(ddni) == 29) {
								d = 31;
								m--;
								ddni = 0;
							}
							else {
								d = 29 + ddni;
								ddni = 0;
							}
						}
						else {
							if (abs(ddni) == 31) {
								d = 31 - 3;
								m--;
								ddni = 0;
							}
							else if (abs(ddni) == 30) {
								d = 31 - 2;
								m--;
								ddni = 0;
							}
							else if (abs(ddni) == 29) {
								d = 31 - 1;
								m--;
								ddni = 0;
							}
							else if (abs(ddni) == 28) {
								d = 31;
								m--;
								ddni = 0;
							}
							else {
								d = 28 + ddni;
								ddni = 0;
							}
						}
					}
				}
				else if (m == 3) {
					if (d != 0) {
						if (d > abs(ddni)) {
							d = d + ddni;
							ddni = 0;
						}
						else {
							if (y % 4 == 0 || (y % 100 == 0 && y % 400 == 0)) {
								ddni = ddni + d;
								d = 29 + ddni;
								m--;
								ddni = 0;
							}
							else {
								ddni = ddni + d;
								d = 28 + ddni;
								m--;
								ddni = 0;
							}
						}
					}
					else {
						if (abs(ddni) == 31) {
							if (y % 4 == 0 || (y % 100 == 0 && y % 400 == 0)) {
								d = 29;
								m--;
								ddni = 0;
							}
							else {
								d = 28;
								m--;
								ddni = 0;
							}
						}
						else {
							d = 31 + ddni;
							ddni = 0;
						}
					}

				}
				else if (m == 4 || m == 6 || m == 9 || m == 11) {
					if (d != 0) {
						if (d > abs(ddni)) {
							d = d + ddni;
							ddni = 0;
						}
						else {
							ddni = ddni + d;
							d = 31 + ddni;
							m--;
							ddni = 0;
						}
					}
					else {
						if (abs(ddni) == 31) {
							d = 31 - 1;
							m--;
							ddni = 0;
						}
						else if (abs(ddni) == 30) {
							d = 31;
							m--;
							ddni = 0;
						}
						else {
							d = 30 + ddni;
							ddni = 0;
						}
					}
				}
				else if (m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
					if (d != 0) {
						if (d > abs(ddni)) {
							d = d + ddni;
							ddni = 0;
						}
						else {
							ddni = ddni + d;
							d = 30 + ddni;
							m--;
							ddni = 0;
						}
					}
					else {
						if (abs(ddni) == 31) {
							d = 30;
							m--;
							ddni = 0;
						}
						else {
							d = 31 + ddni;
							ddni = 0;
						}
					}
				}
				else { provdate = -1; ddni = 0; }
			}
		}
	}
	if (provdate != -1) {
		arr[0] = d;
		arr[1] = m;
		arr[2] = y;
	}
	else {
		arr[0] = -1;
		arr[1] = -1;
		arr[2] = -1;
	}
}
int wow(int d1, int m1, int y1, int h1, int mi1, int s1, int d2, int m2, int y2, int h2, int mi2, int s2) {
	if (y1 > y2 || (y1 == y2 && m1 > m2) || (y1 == y2 && m1 == m2 && d1 > d2) || (y1 == y2 && m1 == m2 && d1 == d2 && h1 > h2) || (y1 == y2 && m1 == m2 && d1 == d2 && h1 == h2 && mi1 > mi2) || (y1 == y2 && m1 == m2 && d1 == d2 && h1 == h2 && mi1 == mi2 && s1 > s2)) {
		return 1;
	}
	else if (y1 < y2 || (y1 == y2 && m1 < m2) || (y1 == y2 && m1 == m2 && d1 < d2) || (y1 == y2 && m1 == m2 && d1 == d2 && h1 < h2) || (y1 == y2 && m1 == m2 && d1 == d2 && h1 == h2 && mi1 < mi2) || (y1 == y2 && m1 == m2 && d1 == d2 && h1 == h2 && mi1 == mi2 && s1 < s2)) {
		return 2;
	}
	else {
		return 0;
	}
}
int shock(int d1, int m1, int y1, int h1, int mi1, int s1, int d2, int m2, int y2, int h2, int mi2, int s2, int some[]) {
	int k = 0, w = 0, d = 0, hh = 0, mm = 0, ss = 0, flag1 = 0, flag2 = 0, flag3 = 0;
	int ta[3];
	if (d1 != d2 || m1 != m2 || y1 != y2) {
		while (flag1 + flag2 + flag3 != 3) {
			date(d, d1, m1, y1, ta);
			d1 = ta[0];
			m1 = ta[1];
			y1 = ta[2];
			int kek[3];
			date(-1, d2, m2, y2, kek);
			if (d1 == kek[0]) {
				flag1 = 1;
				if (m1 == kek[1]) {
					flag2 = 1;
					if (y1 == kek[2]) {
						flag3 = 1;
					}
					else {
						flag3 = 0;
					}
				}
				else {
					flag2 = 0;
				}

			}
			else {
				flag1 = 0;
			}
			if (flag1 + flag2 + flag3 != 3) {
				d = 1;
				k++;
			}
			some[0] = k;
		}
	}
	flag1 = 0, flag2 = 0, flag3 = 0;
	if (h1 != h2 || mi1 != mi2 || s1 != s2) {
		if (h1 < h2) {
			if (d1 != d2) { some[0]++; }
			w = h2 * 60 * 60 + mi2 * 60 + s2 - (h1 * 60 * 60 + mi1 * 60 + s1);
			hh = w / 3600;
			mm = (w - hh * 3600) / 60;
			ss = w - hh * 3600 - mm * 60;
			some[1] = hh;
			some[2] = mm;
			some[3] = ss;
		}
		else {
			w = (60 - s1) + (60 - mi1 - 1) * 60 + (24 - h1 - 1) * 3600 + h2 * 3600 + mi2 * 60 + s2;
			hh = w / 3600;
			mm = (w - hh * 3600) / 60;
			ss = w - hh * 3600 - mm * 60;
			some[1] = hh;
			some[2] = mm;
			some[3] = ss;
		}
	}
	else { some[0]++; }
}
int main() {
	setlocale(LC_ALL, "RUS");
	int k = 1;
	char prov1 = '+', prov2 = '+', prov3 = '+', prov4 = '+', prov6 = '+', prov8 = '+';
	int dni = 0;
	int a1 = 0, a2 = 0, a3 = 0;
	int b1 = 0, b2 = 0, b3 = 0;
	int aa1 = 0, aa2 = 0, aa3 = 0;
	int bb1 = 0, bb2 = 0, bb3 = 0;
	int aaa1 = 0, aaa2 = 0, aaa3 = 0;
	printf("> 1) Время номер 1: %02d:%02d:%02d\n", a1, a2, a3);
	printf("2) Дата номер 1: %02d.%02d.%04d\n", b1, b2, b3);
	printf("3) Время номер 2: %02d:%02d:%02d\n", aa1, aa2, aa3);
	printf("4) Дата номер 2: %02d.%02d.%04d\n", bb1, bb2, bb3);
	printf("5) Посмотреть результат номер 1\n");
	printf("6) Количество дней: %d\n", dni);
	printf("7) Посмотреть результат номер 2\n");
	printf("8) Время номер 3: %02d:%02d:%02d\n", aaa1, aaa2, aaa3);
	printf("9) Посмотреть результат номер 3\n");
	printf("0) Выход \n");
	while (true) {
		int p = getch();
		if (p == 49 || (p == 13 && k == 1)) {
			k = 1;
			system("cls");
			int something[3];
			if (vr(something) == 1) {
				a1 = something[0];
				a2 = something[1];
				a3 = something[2];
				prov1 = '+';
			}
			else {
				prov1 = '-';
				a1 = 0, a2 = 0, a3 = 0;
			}
		}
		else if (p == 50 || (p == 13 && k == 2)) {
			k = 2;
			system("cls");
			int something[3];
			if (da(something) == 1) {
				b1 = something[0];
				b2 = something[1];
				b3 = something[2];
				prov2 = '+';
			}
			else {
				prov2 = '-';
				b1 = 0, b2 = 0, b3 = 0;
			}
		}
		else if (p == 51 || (p == 13 && k == 3)) {
			k = 3;
			system("cls");
			int something[3];
			if (vr(something) == 1) {
				aa1 = something[0];
				aa2 = something[1];
				aa3 = something[2];
				prov3 = '+';
			}
			else {
				prov3 = '-';
				aa1 = 0, aa2 = 0, aa3 = 0;
			}
		}
		else if (p == 52 || (p == 13 && k == 4)) {
			k = 4;
			system("cls");
			int something[3];
			if (da(something) == 1) {
				bb1 = something[0];
				bb2 = something[1];
				bb3 = something[2];
				prov4 = '+';
			}
			else {
				prov4 = '-';
				bb1 = 0, bb2 = 0, bb3 = 0;
			}
		}
		else if (p == 53 || (p == 13 && k == 5)) {
			system("cls");
			k = 5;
			int some[] = { 0, 0, 0, 0 };
			int flag = 0;
			int pa = getch;
			while (pa != 13) {
				system("cls");
				if (b1 == 0 || bb1 == 0) {
					printf("Были введены не все значения \n");
					printf("Для выхода назад нажмите ENTER \n");
				}
				else {
					if (wow(b1, b2, b3, a1, a2, a3, bb1, bb2, bb3, aa1, aa2, aa3) == 1) {
						flag = 0;
						shock(bb1, bb2, bb3, aa1, aa2, aa3, b1, b2, b3, a1, a2, a3, some);
					}
					else if (wow(b1, b2, b3, a1, a2, a3, bb1, bb2, bb3, aa1, aa2, aa3) == 2) {
						flag = 0;
						shock(b1, b2, b3, a1, a2, a3, bb1, bb2, bb3, aa1, aa2, aa3, some);
					}
					else {
						flag = 1;
					}
					printf("Время номер 1: %02d:%02d:%02d \n", a1, a2, a3);
					printf("Дата номер 1: %02d.%02d.%04d ", b1, b2, b3);
					den(ned(b1, b2, b3));
					printf("Время номер 2: %02d:%02d:%02d \n", aa1, aa2, aa3);
					printf("Дата номер 2: %02d.%02d.%04d ", bb1, bb2, bb3);
					den(ned(bb1, bb2, bb3));
					if (flag != 1) {
						if ((some[0] % 10 == 1 && (some[0] % 100 != 11))) { printf("Разница: %d день %02d:%02d:%02d \n", some[0], some[1], some[2], some[3]); }
						else if ((some[0] % 10 == 2) || (some[0] % 10 == 3) || (some[0] % 10 == 4)) { printf("Разница: %d дня %02d:%02d:%02d \n", some[0], some[1], some[2], some[3]); }
						else if ((some[0] % 10 == 5) || (some[0] % 10 == 6) || (some[0] % 10 == 7) || (some[0] % 10 == 8) || (some[0] % 10 == 9) || (some[0] % 100 == 11) || (some[0] == 0)) { printf("Разница: %d дней %02d:%02d:%02d \n", some[0], some[1], some[2], some[3]); }
					}
					else { printf("Разница: даты равны \n"); }
					printf("Для выхода назад нажмите ENTER \n");
				}
				pa = getch();
			}
			system("cls");
			if (prov1 == '+') { printf("1) Время номер 1: %02d:%02d:%02d\n", a1, a2, a3); }
			else { printf("1) Время номер 1: некорректное значение\n"); }
			if (prov2 == '+') { printf("2) Дата номер 1: %02d.%02d.%04d\n", b1, b2, b3); }
			else { printf("2) Дата номер 1: некорректное значение\n"); }
			if (prov3 == '+') { printf("3) Время номер 2: %02d:%02d:%02d\n", aa1, aa2, aa3); }
			else { printf("3) Время номер 2: некорректное значение\n"); }
			if (prov4 == '+') { printf("4) Дата номер 2: %02d.%02d.%04d\n", bb1, bb2, bb3); }
			else { printf("4) Дата номер 2: некорректное значение\n"); }
			printf("> 5) Посмотреть результат номер 1\n");
			if (prov6 == '+') { printf("6) Количество дней: %d\n", dni); }
			else { printf("6) Количество дней: некорректное значение\n"); }
			printf("7) Посмотреть результат номер 2\n");
			if (prov8 == '+') { printf("8) Время номер 3: %02d:%02d:%02d\n", aaa1, aaa2, aaa3); }
			else { printf("8) Время номер 3: некорректное значение\n"); }
			printf("9) Посмотреть результат номер 3\n");
			printf("0) Выход \n");
		}
		else if (p == 54 || (p == 13 && k == 6)) {
			k = 6;
			system("cls");
			int i;
			char aa[100];
			printf("Введите желаемое количество дней от -10000 до 10000 включительно: ");
			gets(aa);
			for (i = 1; i < strlen(aa); i++) {
				if ((isdigit(aa[i]) && isdigit(aa[0])) || (aa[0] == '-' && (isdigit(aa[i])))) {
					prov6 = '+';
					continue;
				}
				else {
					prov6 = '-';
					break;
				}
			}
			if (((aa[0] == '-' && strlen(aa) < 7) || (aa[0] != '-' && strlen(aa) < 6)) && prov6 == '+') {
				sscanf_s(aa, "%d", &dni);
				if (( - 10001 < dni && dni < 10001) || dni == 0) {
					prov6 = '+';
					sscanf_s(aa, "%d", &dni);
				}
				else {
					prov6 = '-';
					dni = 0;
				}
			}
			else {
				prov6 = '-';
				dni = 0;
			}
		}
		else if (p == 55 || (p == 13 && k == 7)) {
			k = 7;
			int arr[3];
			system("cls");
			int pa = getch;
			date(dni, b1, b2, b3, arr);
			while (pa != 13) {
				system("cls");
				if (b1 != 0) {
					printf("Изначальная дата: %02d.%02d.%04d ", b1, b2, b3);
					den(ned(b1, b2, b3));
					printf("Прибавляемое кол-во дней: %d \n", dni);
					printf("Ваша искомая дата: %02d.%02d.%04d ", arr[0], arr[1], arr[2]);
					den(ned(arr[0], arr[1], arr[2]));
					printf("Для выхода назад нажмите ENTER \n");
					pa = getch();
				}
				else {
					printf("Вы не ввели изначальную дату \n");
					printf("Для выхода назад нажмите ENTER \n");
					pa = getch();
				}
			}
			system("cls");
			if (prov1 == '+') { printf("1) Время номер 1: %02d:%02d:%02d\n", a1, a2, a3); }
			else { printf("1) Время номер 1: некорректное значение\n"); }
			if (prov2 == '+') { printf("2) Дата номер 1: %02d.%02d.%04d\n", b1, b2, b3); }
			else { printf("2) Дата номер 1: некорректное значение\n"); }
			if (prov3 == '+') { printf("3) Время номер 2: %02d:%02d:%02d\n", aa1, aa2, aa3); }
			else { printf("3) Время номер 2: некорректное значение\n"); }
			if (prov4 == '+') { printf("4) Дата номер 2: %02d.%02d.%04d\n", bb1, bb2, bb3); }
			else { printf("4) Дата номер 2: некорректное значение\n"); }
			printf("5) Посмотреть результат номер 1\n");
			if (prov6 == '+') { printf("6) Количество дней: %d\n", dni); }
			else { printf("6) Количество дней: некорректное значение\n"); }
			printf("> 7) Посмотреть результат номер 2\n");
			if (prov8 == '+') { printf("8) Время номер 3: %02d:%02d:%02d\n", aaa1, aaa2, aaa3); }
			else { printf("8) Время номер 3: некорректное значение\n"); }
			printf("9) Посмотреть результат номер 3\n");
			printf("0) Выход \n");
		}
		else if (p == 56 || (p == 13 && k == 8)) {
			k = 8;
			system("cls");
			int something[3];
			if (vr(something) == 1) {
				aaa1 = something[0];
				aaa2 = something[1];
				aaa3 = something[2];
				prov8 = '+';
			}
			else {
				prov8 = '-';
				aaa1 = 0, aaa2 = 0, aaa3 = 0;
			}
		}
		else if (p == 57 || (p == 13 && k == 9)) {
			k = 9;
			system("cls");
			int h = 0, m = 0, s = 0, hh = 0, mm = 0, ss = 0;
			ss = (a3 + aaa3) / 60;
			mm = (a2 + aaa2 + ss) / 60;
			hh = (a1 + aaa1 + mm) / 24;
			if (a3 + aaa3 > 59) {
				s = (a3 + aaa3) - 60 * ss;
			}
			else {
				s = a3 + aaa3;
			}
			if (a2 + aaa2 + ss > 59) {
				m = a2 + aaa2 + ss - 60 * mm;
			}
			else {
				m = a2 + aaa2 + ss;
			}
			if (a1 + aaa1 + mm > 23) {
				h = a1 + aaa1 + mm - (24 * hh);
			}
			else {
				h = a1 + aaa1 + mm;
			}
			int pa = getch;
			while (pa != 13) {
				system("cls");
				printf("Изначальное время: %02d:%02d:%02d\n", a1, a2, a3);
				printf("Прибавляемое время: %02d:%02d:%02d\n", aaa1, aaa2, aaa3);
				printf("Ваше искомое время: %02d:%02d:%02d\n", h, m, s);
				printf("Для выхода назад нажмите ENTER \n");
				pa = getch();
			}
			system("cls");
			if (prov1 == '+') { printf("1) Время номер 1: %02d:%02d:%02d\n", a1, a2, a3); }
			else { printf("1) Время номер 1: некорректное значение\n"); }
			if (prov2 == '+') { printf("2) Дата номер 1: %02d.%02d.%04d\n", b1, b2, b3); }
			else { printf("2) Дата номер 1: некорректное значение\n"); }
			if (prov3 == '+') { printf("3) Время номер 2: %02d:%02d:%02d\n", aa1, aa2, aa3); }
			else { printf("3) Время номер 2: некорректное значение\n"); }
			if (prov4 == '+') { printf("4) Дата номер 2: %02d.%02d.%04d\n", bb1, bb2, bb3); }
			else { printf("4) Дата номер 2: некорректное значение\n"); }
			printf("5) Посмотреть результат номер 1\n");
			if (prov6 == '+') { printf("6) Количество дней: %d\n", dni); }
			else { printf("6) Количество дней: некорректное значение\n"); }
			printf("7) Посмотреть результат номер 2\n");
			if (prov8 == '+') { printf("8) Время номер 3: %02d:%02d:%02d\n", aaa1, aaa2, aaa3); }
			else { printf("8) Время номер 3: некорректное значение\n"); }
			printf("> 9) Посмотреть результат номер 3\n");
			printf("0) Выход \n");
		}
		else if (p == 48 || (p == 13 && k == 10)) {
			k = 10;
			exit();
		}
		else if (p == 80) {
			if (k == 10) {
				continue;
			}
			else {
				k++;
			}
		}
		else if (p == 72) {
			if (k == 1) {
				continue;
			}
			else {
				k--;
			}
		}
		system("cls");
		if (k == 1) {
			if (prov1 == '+') { printf("> 1) Время номер 1: %02d:%02d:%02d\n", a1, a2, a3); }
			else { printf("> 1) Время номер 1: некорректное значение\n"); }
		}
		else {
			if (prov1 == '+') { printf("1) Время номер 1: %02d:%02d:%02d\n", a1, a2, a3); }
			else { printf("1) Время номер 1: некорректное значение\n"); }
		}
		if (k == 2) {
			if (prov2 == '+' && b1 != 0) { 
				printf("> 2) Дата номер 1: %02d.%02d.%04d ", b1, b2, b3);
				den(ned(b1, b2, b3));
			}
			else if (prov2 == '+' && b1 == 0){ printf("> 2) Дата номер 1: %02d.%02d.%04d\n", b1, b2, b3); }
			else { printf("> 2) Дата номер 1: некорректное значение\n"); }
		}
		else {
			if (prov2 == '+' && b1 != 0) {
				printf("2) Дата номер 1: %02d.%02d.%04d ", b1, b2, b3);
				den(ned(b1, b2, b3));
			}
			else if (prov2 == '+' && b1 == 0) { printf("2) Дата номер 1: %02d.%02d.%04d\n", b1, b2, b3); }
			else { printf("2) Дата номер 1: некорректное значение\n"); }
		}
		if (k == 3) {
			if (prov3 == '+') { printf("> 3) Время номер 2: %02d:%02d:%02d\n", aa1, aa2, aa3); }
			else { printf("> 3) Время номер 2: некорректное значение\n"); }
		}
		else {
			if (prov3 == '+') { printf("3) Время номер 2: %02d:%02d:%02d\n", aa1, aa2, aa3); }
			else { printf("3) Время номер 2: некорректное значение\n"); }
		}
		if (k == 4) {
			if (prov4 == '+' && bb1 != 0) {
				printf("> 4) Дата номер 2: %02d.%02d.%04d ", bb1, bb2, bb3);
				den(ned(bb1, bb2, bb3));
			}
			else if (prov4 == '+' && bb1 == 0) { printf("> 4) Дата номер 2: %02d.%02d.%04d\n", bb1, bb2, bb3); }
			else { printf("> 4) Дата номер 2: некорректное значение\n"); }
		}
		else {
			if (prov4 == '+' && bb1 != 0) {
				printf("4) Дата номер 2: %02d.%02d.%04d ", bb1, bb2, bb3);
				den(ned(bb1, bb2, bb3));
			}
			else if (prov4 == '+' && bb1 == 0) { printf("4) Дата номер 2: %02d.%02d.%04d\n", bb1, bb2, bb3); }
			else { printf("4) Дата номер 2: некорректное значение\n"); }
		}
		if (k == 5) { printf("> 5) Посмотреть результат номер 1\n"); }
		else { printf("5) Посмотреть результат номер 1\n"); }
		if (k == 6) {
			if (prov6 == '+') { printf("> 6) Количество дней: %d\n", dni); }
			else { printf("> 6) Количество дней: некорректное значение\n"); }
		}
		else {
			if (prov6 == '+') { printf("6) Количество дней: %d\n", dni); }
			else { printf("6) Количество дней: некорректное значение\n"); }
		}
		if (k == 7) { printf("> 7) Посмотреть результат номер 2\n"); }
		else { printf("7) Посмотреть результат номер 2\n"); }
		if (k == 8) {
			if (prov8 == '+') { printf("> 8) Время номер 3: %02d:%02d:%02d\n", aaa1, aaa2, aaa3); }
			else { printf("> 8) Время номер 3: некорректное значение\n"); }
		}
		else {
			if (prov8 == '+') { printf("8) Время номер 3: %02d:%02d:%02d\n", aaa1, aaa2, aaa3); }
			else { printf("8) Время номер 3: некорректное значение\n"); }
		}
		if (k == 9) { printf("> 9) Посмотреть результат номер 3\n"); }
		else { printf("9) Посмотреть результат номер 3\n"); }
		if (k == 10) { printf("> 0) Выход \n"); }
		else { printf("0) Выход \n"); }

	}
	return 0;
}