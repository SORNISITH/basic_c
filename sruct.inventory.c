#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 50
#define MAX_PART 1000
#define ERR_ID_NOTFOUND printf("❌ID not found !!\n");

// share funtion
void get_inventory(int i);
bool check_id_exist(int id);
int program_option(void);
void display_all_inventory(void);
int check_id_index(int id);
void find_inventory(void);
void insert_inventory(int id, char* name, int count);
void insert_inventory_input(void);
void update_inventory(void);
void add_inventory(int current_inv, int id, char* name, int count);
void read_char(char* str);
void init_database();
void push_csv(int id);

struct {
    int id;
    char name[NAME_LEN];
    int count;
} INVENTORY[MAX_PART];
int current_inventory = 0;

int main(int argc, char* argv[])
{
    init_database();
    //  system("clear");
    system("clear");
    bool program_state = true;
    while (program_state) {
        switch (program_option()) {
        case 1:
            insert_inventory_input();
            break;
        case 2:
            find_inventory();
            break;
        case 3:
            update_inventory();
            break;
        case 4:
            printf("4");
            break;
        case 0:
            display_all_inventory();
            break;
        case -1:
        default:
            printf("THANKS U FOR USING MY APP !!");
            program_state = false;
        }
    }
    return EXIT_SUCCESS;
}
bool check_id_exist(int id)
{
    for (int i = 0; i <= current_inventory; i++) {
        if (id == INVENTORY[i].id) {
            return true;
        }
    }
    return false;
}
int check_id_index(int id)
{
    for (int i = 0; i <= current_inventory; i++) {
        if (id == INVENTORY[i].id) {
            return i;
        }
    }
    return -1;
}
void display_all_inventory(void)
{
    if (current_inventory > 0) {
        system("clear");
        printf("\t Welcome to INVENTORY\n");
        printf("\t --------------------\n");
        printf("\t OBJ \tID \t NAME \t\t\t COUNT \n");
        // for (int i = current_inventory - 1; i >= 0; i--) {
        //     get_inventory(i);
        // }
        for (int i = 0; i < current_inventory; i++) {
            get_inventory(i);
        }

    } else {
        system("clear");
        printf("\t N0 INVENT0RY F0UND!\n");
    }
}
void find_inventory(void)
{
    int id = -1;
    printf("Enter ID : ");
    scanf("%d", &id);
    if (check_id_exist(id)) {
        printf("\t FIND \tID \t NAME \t\t\t COUNT \n");
        get_inventory(id);
    } else {
        ERR_ID_NOTFOUND;
    }
}

void get_inventory(int i)
{
    printf("\t %2d \t %2d \t %-20s \t %5d \n", i, INVENTORY[i].id, INVENTORY[i].name, INVENTORY[i].count);
}

void insert_inventory_input(void)
{
    if (current_inventory >= MAX_PART) {
        printf(" ERROR ❌ MAXIMUM STOCK MEMORY!!l");
        return;
    }

    int id = 0, count = 0;
    char name[NAME_LEN + 1];
    printf("Add INVENTORY... \n");
    printf("Enter ID : ");
    scanf("%d", &id);
    while (true) {
        if (check_id_exist(id)) {
            ERR_ID_NOTFOUND;
            printf("Enter New ID : ");
            scanf("%d", &id);
        } else {
            break;
        }
    }
    printf("Enter NAME : ");
    read_char(name);
    printf("Enter COUNT : ");
    scanf("%d", &count);
    if (!id || !count || (name[0] == ' ')) {
        printf("❌ Please Enter Secific INFO!!");
    }
    add_inventory(current_inventory, id, name, count);
    push_csv(current_inventory);
    current_inventory++;
    return;
}
void push_csv(int currentid)
{
    FILE* fp = fopen("./MOCK_DATA.csv", "a");
    if (!fp) {
        printf("ERR FILE NOT FOUND!");
    } else {
        fprintf(fp, "%d,%s,%d", INVENTORY[currentid].id, INVENTORY[currentid].name, INVENTORY[currentid].count);
    }
    fclose(fp);
}

void init_database()
{
    FILE* filecsv = fopen("./MOCK_DATA.csv", "r");
    char line[1024];
    size_t len = sizeof(line);
    if (!filecsv) {
        printf("ERR FILE NOT FOUND!");
    } else {
        fgets(line, len, filecsv); // ignore first line
        while (fgets(line, len, filecsv)) {
            int id, count;
            char name[NAME_LEN];
            sscanf(line, "%d,%20[^,],%d", &id, name, &count);
            insert_inventory(id, name, count);
        }
    }
    fclose(filecsv);
}
void insert_inventory(int id, char* name, int count)
{
    if (current_inventory >= MAX_PART) {
        printf("❌ error MAXIMUM STOCK MEMORY!!l");
        return;
    }
    add_inventory(current_inventory, id, name, count);
    current_inventory++;
    return;
}

void read_char(char* str)
{
    int ch = getchar();
    while (ch == '\n') {
        ch = ' ';
        break;
    }
    while (ch != '\n' && ch != EOF) {
        ch = getchar();
        *str = ch;
        str++;
    }
    *str = '\0';
}

void update_inventory(void)
{
    display_all_inventory();
    int val_id = -1;
    printf("Enter ID to Update : ");
    scanf("%d", &val_id);
    int inv_id = check_id_exist(val_id);

    if (inv_id >= 0 && inv_id <= MAX_PART) {
        int count;
        char name[NAME_LEN];
        int old_id = INVENTORY[inv_id].id;
        printf("UPDATE ... %d \n", old_id);
        printf("Enter NAME : ");
        read_char(name);
        printf("Enter COUNT : ");
        scanf("%d", &count);
        add_inventory(inv_id, old_id, name, count);
        printf("  ☑️ SUCESSFULLY UPDATE ! => ");
        get_inventory(inv_id);
    } else {
        ERR_ID_NOTFOUND;
        if (current_inventory > 0 && current_inventory < MAX_PART) {
            update_inventory();
        }
    }
}
void add_inventory(int current_inv, int id, char* name, int count)
{
    int index = 0;
    char* p = name;
    while (*p != '\n') {
        INVENTORY[current_inv].name[index++] = *p;
        p++;
    }
    INVENTORY[current_inv].id = id;
    INVENTORY[current_inv].count = count;
    printf("  ☑️ SUCESSFULLY Add ! => ");
    get_inventory(current_inv);
}

int program_option(void)
{
    int opt = 0;
    printf("\nEnter Options");
    printf(" : ( 0 = DisplayAll ,  1 = insert , 2 = find\n  3 = update  , 4 = delete ) ");
    printf(" =>> ");
    scanf("%d", &opt);
    return opt;
}
