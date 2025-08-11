<h1 align="center">Push Swap</h1>

<p align="center">
  <a href="#explication-fr">🇫🇷</a> | <a href="#explanation-en">🇬🇧</a>
</p>

---

## <a name="explication-fr"></a>🇫🇷 Explication

### Ce qu’on devait faire

Pour ce projet, l’objectif était de créer un programme capable de trier une liste de nombres fournie, en respectant certaines contraintes :
- Les nombres sont **uniques** (pas de doublons) et ne dépassent pas la taille d’un `int`.
- Pour effectuer le tri, on ne peut utiliser que **deux stacks maximum** (stack A et stack B).
- Le but est d’utiliser **le moins d’instructions possible**.

#### Instructions disponibles :
- **`push (a/b)`** : Déplace le premier élément vers le haut de la stack cible (ex. `push_a` déplace de B vers A).
- **`rotate (a/b/r)`** : Déplace l’élément du haut de la stack vers le bas, tout en préservant l’ordre des autres éléments. Avec `r`, les deux stacks sont affectées en une seule instruction.
- **`reverse_rotate (a/b/r)`** : Déplace l’élément du bas de la stack vers le haut, en conservant l’ordre du reste. Avec `r`, les deux stacks sont affectées simultanément.
- **`swap (a/b/s)`** : Échange les deux premiers éléments de la stack cible. Avec `s`, les deux stacks sont échangées en une seule instruction.


### Comment je m’y suis pris

Dans ce projet, je voulais approfondir ma maîtrise de deux concepts : les **pointeurs de type `void *`** et les **pointeurs sur fonctions**. Pour cela, j’ai décidé d’utiliser les fonctions de listes chaînées de ma bibliothèque [`libft`](https://github.com/BenjamsC08/42_00_libft).

#### Étapes suivies :

1. **Création d’une structure de données**  
   J’ai défini une structure `data` qui constitue le contenu des nœuds de ma liste chaînée. Pour rendre la liste **doublement chaînée**, j’ai inclus un pointeur vers le nœud précédent en plus des données habituelles.

2. **Recherche d’un algorithme adapté**  
   Après deux tentatives infructueuses pour concevoir mon propre algorithme, j’ai étudié les algorithmes existants. J’ai opté pour une approche qui cherche à chaque étape **le meilleur coup possible**, jusqu’à ce que :  
   - La stack A soit triée, ou  
   - Sa taille soit réduite à 3 éléments.  
   L’objectif n’était pas d’avoir le programme le plus rapide, mais de générer la **séquence d’instructions la plus courte** pour trier les nombres.

3. **Création d’une structure pour les instructions**  
   J’ai conçu une structure `s_move` pour stocker les informations sur chaque instruction :  
   - Le nom de l’instruction (défini via des macros),  
   - La stack concernée (A, B ou les deux),  
   - Le coût de l’opération,  
   - Un pointeur sur la fonction à exécuter.  
   Cette structure est souvent utilisée dans un tableau : `[0]` pour la source, `[1]` pour la destination, `[2]` pour les deux stacks (cas des instructions combinées comme `rr` ou `rrr`).

4. **Optimisation des mouvements**  
   Pour réduire le nombre d’instructions, j’ai privilégié les opérations combinées comme `rr` ou `rrr` lorsque cela était possible. À chaque étape :  
   - Je calcule le coût de chaque mouvement,  
   - Je choisis le moins coûteux,  
   - J’exécute ce mouvement et passe au nombre suivant.

5. **Gestion de la fin du tri**  
   Une fois que la stack A atteint une taille de 3 éléments, j’applique une stratégie inverse : je transfère les éléments de la stack B vers A en les plaçant dans un **ordre croissant**. Quand la stack B est vide, je cherche la plus petite valeur dans A :  
   - Si son index est supérieur à la moitié de la taille de la stack, j’utilise `reverse_rotate`.  
   - Sinon, j’utilise `rotate`, jusqu’à ce qu’elle soit en première position.

---

## <a name="explanation-en"></a>🇬🇧 Explanation

### What We Had to Do

For this project, the goal was to create a program capable of sorting a provided list of numbers while adhering to certain constraints:
- The numbers are **unique** (no duplicates) and do not exceed the size of an `int`.
- To perform the sorting, only **two stacks maximum** (stack A and stack B) can be used.
- The objective is to use **the fewest instructions possible**.

#### Available Instructions:
- **`push (a/b)`**: Moves the first element to the top of the target stack (e.g., `push_a` moves from B to A).
- **`rotate (a/b/r)`**: Moves the top element of the stack to the bottom while preserving the order of the other elements. With `r`, both stacks are rotated in a single instruction.
- **`reverse_rotate (a/b/r)`**: Moves the bottom element of the stack to the top while maintaining the order of the rest. With `r`, both stacks are affected simultaneously.
- **`swap (a/b/s)`**: Swaps the first two elements of the target stack. With `s`, both stacks are swapped in a single instruction.

### How I Approached It

In this project, I wanted to deepen my understanding of two concepts: **void * type pointers** and **function pointers**. To achieve this, I decided to use the linked list functions from my [`libft`](https://github.com/BenjamsC08/42_00_libft).

#### Steps Followed:

1. **Creating a Data Structure**  
   I defined a `data` structure that forms the content of the nodes in my linked list. To make the list **doubly linked**, I included a pointer to the previous node in addition to the usual data.

2. **Finding a Suitable Algorithm**  
   After two unsuccessful attempts to design my own algorithm, I studied existing ones. I settled on an approach that, at each step, seeks **the best possible move** until:  
   - Stack A is sorted, or  
   - Its size is reduced to 3 elements.  
   The goal wasn’t to create the fastest program but to generate the **shortest sequence of instructions** to sort the numbers.

3. **Creating a Structure for Instructions**  
   I designed an `s_move` structure to store information about each instruction:  
   - The name of the instruction (defined via macros),  
   - The affected stack (A, B, or both),  
   - The cost of the operation,  
   - A pointer to the function to execute.  
   This structure is often used in an array: `[0]` for the source, `[1]` for the destination, `[2]` for both stacks (for combined instructions like `rr` or `rrr`).

4. **Optimizing Movements**  
   To reduce the number of instructions, I prioritized combined operations like `rr` or `rrr` whenever possible. At each step:  
   - I calculate the cost of each move,  
   - I choose the least costly one,  
   - I execute that move and proceed to the next number.

5. **Handling the End of the Sorting**  
   Once stack A reaches a size of 3 elements, I apply a reverse strategy: I transfer elements from stack B to A, placing them in **ascending order**. When stack B is empty, I look for the smallest value in A:  
   - If its index is greater than half the stack’s size, I use `reverse_rotate`.  
   - Otherwise, I use `rotate` until it reaches the first position.
