struct stack_t{
    int val;
    struct stack_t *prev;
};

static void Clean_all(struct stack_t *head);
static struct stack_t* Delete_element(struct stack_t *old_el);
static struct stack_t* Add_element(struct stack_t *last, int num);
static int Symbol_code(char symbol);

bool isValid(char * s)
{
    int tmp;
    struct stack_t  *head,
                    *zero_el = (struct stack_t *) malloc(sizeof(struct stack_t));
    zero_el->val = 0;
    zero_el->prev = NULL;

    head = Add_element(zero_el, Symbol_code(s[0]));
    if(head->val < 0)
    {
        printf("1\n");
        Clean_all(head);
        return false;
    }


    for(int i  = 1; s[i] != '\0'; ++i)
    {
        tmp = Symbol_code(s[i]);
        if(tmp < 0)
        {
            if(head->val + tmp)
            {
                Clean_all(head);
                printf("2\n");
                return false;
            }
            else
                head = Delete_element(head);
        }
        else
            head = Add_element(head, tmp);
    }


    if(head->prev)
    {
        Clean_all(head);
        printf("3\n");
        return false;
    }
    return true;

}

static void Clean_all(struct stack_t *head)
{
    struct stack_t *new_head;
    while(head != NULL)
    {
        new_head = head->prev;
        free(head);
        head = new_head;
    }
}

static struct stack_t* Delete_element(struct stack_t *old_el)
{
    struct stack_t *new_head = old_el->prev;
    free(old_el);
    return new_head;
}


static struct stack_t* Add_element(struct stack_t *last, int num)
{
    struct stack_t *new_el = (struct stack_t *) malloc(sizeof(struct stack_t));
    new_el->prev = last;
    new_el->val = num;
    return new_el;
}


static int Symbol_code(char symbol)
{
    if(symbol == '(')
        return 1;
    if(symbol == ')')
        return -1;
    if(symbol == '{')
        return 2;
    if(symbol == '}')
        return -2;
    if(symbol == '[')
        return 3;
    if(symbol == ']')
        return -3;
    return 0;
}
