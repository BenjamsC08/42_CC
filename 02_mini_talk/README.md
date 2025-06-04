<h1 align="center">Mini_Talk</h1>

<p align="center">
  <a href="#explication-fr">🇫🇷</a> | <a href="#explanation-en">🇬🇧</a>
</p>

---

## <a name="explication-fr"></a>🇫🇷 Explication
### Objectif
Le projet **Mini-Talk** consiste à créer deux programmes, un serveur et un client, qui communiquent entre eux à l’aide de signaux UNIX. Le client envoie une chaîne de caractères au serveur bit par bit, et le serveur doit reconstruire cette chaîne puis l’afficher une fois la transmission complète.

### Fonctionnement
#### Approche adoptée
Après plusieurs essais, j’ai implémenté un système de communication en "ping-pong" entre le client et le serveur :
- **Client** : Pour chaque caractère de la chaîne, le client envoie ses 8 bits en utilisant :
  - `SIGUSR1` pour un bit à `1`,
  - `SIGUSR2` pour un bit à `0`.  
  À chaque bit envoyé, le client attend une réponse du serveur avant de passer au suivant. Une fois la chaîne entièrement transmise, le client s’arrête.
- **Serveur** : Le serveur écoute en boucle infinie les signaux reçus. Lorsqu’un signal arrive :
  - Il détermine s’il s’agit de `SIGUSR1` ou `SIGUSR2` pour reconstruire le caractère bit par bit.
  - Après chaque bit reçu, il renvoie `SIGUSR1` au client pour confirmer la réception.
  - Quand un caractère est complet (et vaut `0` pour marquer la fin), il l’affiche et envoie `SIGUSR2` au client pour terminer la communication.

#### Schéma général
1. Le client convertit chaque caractère en une séquence de 8 bits.
2. Il envoie ces bits un par un au serveur via des signaux.
3. Le serveur reconstruit les caractères et les affiche une fois la transmission terminée.

### Ce que j’ai appris
- Utilisation des **signaux UNIX** (`SIGUSR1`, `SIGUSR2`) pour la communication inter-processus.
- Techniques d’envoi et de réception de signaux.
- Gestion de la synchronisation entre deux processus via un échange de signaux.

---

## <a name="explanation-en"></a>🇬🇧 Explanation
### Objective
The **Mini-Talk** project involves creating two programs, a server and a client, that communicate with each other using UNIX signals. The client sends a string to the server bit by bit, and the server must reconstruct this string and display it once the transmission is complete.

### How It Works
#### Approach Adopted
After several attempts, I implemented a "ping-pong" communication system between the client and the server:
- **Client**: For each character in the string, the client sends its 8 bits using:
  - `SIGUSR1` for a bit set to `1`,
  - `SIGUSR2` for a bit set to `0`.  
  After sending each bit, the client waits for a response from the server before proceeding to the next one. Once the entire string has been sent, the client stops.
- **Server**: The server listens in an infinite loop for incoming signals. When a signal is received:
  - It determines whether it’s `SIGUSR1` or `SIGUSR2` to reconstruct the character bit by bit.
  - After receiving each bit, it sends `SIGUSR1` back to the client to acknowledge receipt.
  - Once a character is fully received (and equals `0` to mark the end), it displays it and sends `SIGUSR2` to the client to end the communication.

#### General Flow
1. The client converts each character into a sequence of 8 bits.
2. It sends these bits one by one to the server using signals.
3. The server reconstructs the characters and displays them once the transmission is finished.

### What I Learned
- Using **UNIX signals** (`SIGUSR1`, `SIGUSR2`) for inter-process communication.
- Techniques for sending and receiving signals.
- Managing synchronization between two processes through signal exchange.
