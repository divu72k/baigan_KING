#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int cf, px, py, pz;
    struct node *link;
} NODE;

NODE* getnode() {
    NODE *new_node = (NODE*) malloc(sizeof(NODE));
    new_node->link = NULL;
    return new_node;
}

NODE* insert_rear(int cf, int px, int py, int pz, NODE *head) {
    NODE *new_node = getnode();
    new_node->cf = cf;
    new_node->px = px;
    new_node->py = py;
    new_node->pz = pz;
    new_node->link = head->link;
    head->link = new_node;
    return head;
}

NODE* read_poly(NODE *head) {
    int cf, px, py, pz;
    printf("\nEnter the coefficients, powers of x, y, z:\n");
    while (1) {
        printf("Enter cf, px, py, pz (0, 0, 0, 0 to stop): ");
        scanf("%d%d%d%d", &cf, &px, &py, &pz);
        if (cf == 0 && px == 0 && py == 0 && pz == 0)
            break;
        head = insert_rear(cf, px, py, pz, head);
    }
    return head;
}

void display(NODE *head) {
    NODE *p = head->link;
    while (p != head) {
        printf("%dx^%dy^%dz^%d + ", p->cf, p->px, p->py, p->pz);
        p = p->link;
    }
    printf("\n");
}

NODE* add_poly(NODE *h1, NODE *h2, NODE*h3) {
    NODE *p1 = h1->link, *p2 = h2->link, *p3 = h3;
    int x1, y1, z1, x2, y2, z2, cf;
    while (p1 != h1 || p2 != h2) {
        if (p1 == h1) {
            p1 = h1->link;
            continue;
        }
        if (p2 == h2) {
            p2 = h2->link;
            continue;
        }
        x1 = p1->px;
        y1 = p1->py;
        z1 = p1->pz;
        x2 = p2->px;
        y2 = p2->py;
        z2 = p2->pz;
        if (x1 == x2 && y1 == y2 && z1 == z2) {
            cf = p1->cf + p2->cf;
            if (cf>0){
                p3 = insert_rear(cf, x1, y1, z1, p3);
            }
            p1->cf = 0;
            p2->cf = 0;
        } else if (x1 == x2 && y1 > y2) {
            p3 = insert_rear(p1->cf, x1, y1, z1, p3);
            p1->cf = 0;
        } else if (x1 == x2 && y1 < y2) {
            p3 = insert_rear(p2->cf, x2, y2, z2, p3);
            p2->cf = 0;
        } else if (x1 > x2) {
            p3 = insert_rear(p1->cf, x1, y1, z1, p3);
            p1->cf = 0;
        } else {
            p3 = insert_rear(p2->cf, x2, y2, z2, p3);
            p2->cf = 0;
        }
        p1 = p1->link;
        p2 = p2->link;
    }
   return h3;
}

int main() {
    NODE *h1 = getnode(), *h2 = getnode(), *h3 = getnode();
    h1->link = h1;
    h2->link = h2;
    h3->link = h3;
    printf("\nEnter the first polynomial: ");
    h1 = read_poly(h1);
    printf("\nEnter the second polynomial: ");
    h2 = read_poly(h2);
    printf("\nFirst polynomial: ");
    display(h1);
    printf("Second polynomial: ");
    display(h2);
    printf("Sum of the polynomials: ");
    add_poly(h1, h2, h3);
    display(h3);
    return 0;
}