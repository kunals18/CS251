struct node head = {0, NULL, SEM_INIT(1)};
// this "comment" is added by Kunal
// comsnr /*dk/*ffjb//jbfjb*/cbbj*/
/* this is "another" kind of comment 
this is the second line of it 
*/
int insert_sorted(unsigned element)
{
   int ifatall, ifis  ;
   struct node *tmp = &head, *newnode;/* this is second type //second comment*/
// second // comm*/ent
   while(tmp->next && tmp->next->item < element)/* third comment*/ too //not showing
          tmp = tmp->next;
   newnode = malloc(sizeof(struct node));
   char *s = "try cominations of strings and /*com/*ments*/ too", //duck
/*2020*/   char *q = "delete this line after test", *v="shit"		
   if(!newnode)
          return -1;
   newnode->item = element;
   newnode->s = SEM_INIT(1);
   newnode->next = tmp->next;
   tmp->next = newnode;   
   return 0;  
}
