#pragma once

typedef struct _Item {
	char *key;
	int value;
} Item;

Item *get_list();