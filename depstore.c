#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct items
{
  int itemcode;
  char itemname[20];
  int quantity;
  int rate;
} itt;

void itementry ();
void itemdisplay ();
void itemdel ();
void makebill ();
void mainmenu ();
void option ();

void
main ()
{
  int userid, pass;
  printf ("...............\n");
  printf ("ENTER USER ID\n-->");
  scanf ("%d", &userid);
  printf ("...............\n");
  printf ("ENTER PASSWORD\n-->");
  scanf ("%d", &pass);
  printf
    ("--------------------------------------------------------------------------------\n");

  if (userid == pass)
    printf ("LOGIN SUCCESSFUL !!");
  else
    {
      printf ("ERROR LOGGING IN");
      exit (1);
    }
  mainmenu ();
  getch ();
}

void
itementry ()
{
  FILE *f;

  int bar, i, np, quan;
  float price;
  char ptype[30];

  f = fopen ("entergoods.txt", "w+");

  printf ("kindly enter the number of products: ");
  scanf ("%d", &np);
  printf
    ("--------------------------------------------------------------------------------\n");
  if (np > 0)
    {
      for (i = 0; i < np; i++)
	printf ("barcode of product %d : ", i + 1);
      scanf ("%d", &bar);
      printf ("enter product type    : ");
      scanf ("%s", ptype);
      printf ("enter quantity        : ");
      scanf ("%d", &quan);
      printf ("enter price           : ");
      scanf ("%f", &price);
    }
  if (np > 0)
    {
      for (i = 0; i < np; i++)
	printf ("information saved\nsaved details:");
      printf ("\nBARCODE\t\tPRODUCT\t\tCOST(rupees)\t\tQUANTITY");
      printf
	("\n--------------------------------------------------------------------------------\n");
      printf ("%d\t\t%s\t\t%f\t\t%d", bar, ptype, price, quan);
    }
  fclose (f);
  getch ();
}

void
itemdisplay ()
{
  FILE *f1;
  char k;
  f1 = fopen ("items.txt", "r+");
  if (f1 == NULL)
    {
      printf ("error in opening file");
      exit (1);
    }
  else
    {
      k = getc (f1);
      while (k != EOF)
	{
	  putchar (k);
	  k = getc (f1);
	}
      fclose (f1);
    }
  void option ();
  getch ();

}

void
itemdel ()
{
  FILE *f1, *temp;
  int barcode;

  f1 = fopen ("items.txt", "rb");
  temp = fopen ("tempgoods.txt", "wb");
  printf ("\nenter the barcode of the product to be deleted : ");
  scanf ("%d", &barcode);

  {
    if (itt.itemcode == barcode)
      {
	rename ("tempgoods.txt", "items.txt");
	printf ("\n DELETED SUCCESSFULLY");
      }
    else
      printf ("item to be deleted does not exist");

    fclose (f1);
    fclose (temp);

  }
  void option ();
  getch ();

}

void
makebill ()
{
  int opn;
  int bar, i, totq = 0;
  int np, quan;
  float totd = 0, total = 0, disc, price;
  float amtg, change, bill;
  char ptype[30], bno[30], name[30], date[30], phno[10];

  printf
    ("--------------------------------------------------------------------------------\n");

  printf
    ("--------------------------------------------------------------------------------\n");
  printf ("ENTER DATE     : ");
  scanf ("%s", date);
  printf ("BILL NUMBER    : ");
  scanf ("%s", bno);
  printf ("CUSTOMERS NAME : ");
  scanf ("%s", name);
  printf ("PHONE NUMBER   : ");
  scanf ("%s", phno);
  printf
    ("\n--------------------------------------------------------------------------------\n");
  printf ("kindly enter the number of products: ");
  scanf ("%d", &np);
  printf
    ("--------------------------------------------------------------------------------\n");
  if (np > 0)
    for (i = 0; i < np; i++)
      {
	printf ("barcode of product %d : ", i + 1);
	scanf ("%d", &bar);
	printf ("enter product type    : ");
	scanf ("%s", ptype);
	printf ("enter quantity        : ");
	scanf ("%d", &quan);
	totq = totq + quan;
	printf ("enter price           : ");
	scanf ("%f", &price);
	printf ("enter discount        : ");
	scanf ("%f", &disc);
	totd = totd + (disc * quan);
	total = total + (price * quan);
	printf
	  ("\n--------------------------------------------------------------------------------\n");

      }

  bill = total - totd;
  printf ("amount given by customer =");
  scanf ("%f", &amtg);
  change = amtg - bill;
  printf ("please return amount = %f rupees", change);
  printf
    ("\n--------------------------------------------------------------------------------");


  printf
    ("--------------------------------------------------------------------------------\n");
  printf ("\n*************************RECEIPT****************************\n");
  printf ("total number of items   = %d\n", totq);
  printf ("price of the items      = %f rupees\n", total);
  printf ("total discount availed  = %f rupees\n\n", totd);
  printf ("total bill              = %f rupees", bill);
  printf
    ("\n--------------------------------------------------------------------------------");
  printf ("\namount given by %s = %f rupees ", name, amtg);
  printf ("\nchange returned = %f rupees", change);
  printf
    ("\n--------------------------------------------------------------------------------");

  printf
    ("\n--------------------------------------------------------------------------------\n\n");
  printf
    ("choose option|n\n\n\t1-->NEXT CUSTOMER\n\t2-->MAIN MENU\n\t3-->press any other key to EXIT");
  printf ("\noption = ");
  scanf ("%d", &opn);

  switch (opn)
    {
    case 1:
      fflush (stdin);
      makebill ();
      break;

    case 2:
      fflush (stdin);
      mainmenu ();
      break;

    case 3:
      printf ("exit");
      exit (1);
    }


  getch ();


}

void
mainmenu ()
{
  int choice;
  printf
    ("\n--------------------------------------------------------------------------------\n");
  printf ("\n************ MAIN MENU ************");
  printf
    ("\n\n CHOOSE MODE \n\t1-->Goods Entry\n\t2-->Display goods\n\t3-->Delete goods\n\t4-->Make Bill");
  printf ("\nMODE= ");
  scanf ("%d", &choice);
  printf
    ("--------------------------------------------------------------------------------\n");

  switch (choice)
    {
    case 1:
      itementry ();
      break;

    case 2:
      itemdisplay ();
      break;

    case 3:
      itemdel ();
      break;

    case 4:
      makebill ();
      break;
    default:
      printf ("mode dosen't exist, choose again");
      exit (1);

    }

  getch ();
}

void
option ()
{
  int opn;
  printf
    ("choose option|n\n\n\t1-->MAIN MENU\n\t2-->press any other key to EXIT");
  printf ("\noption = ");
  scanf ("%d", &opn);

  switch (opn)
    {

    case 1:
      fflush (stdin);
      mainmenu ();
      break;

    case 2:
      printf ("exit");
      exit (1);
    }
  getch ();
