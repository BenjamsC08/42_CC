<h1 align="center">Philosophers</h1>

<p align="center">
  <a href="#explication-fr">🇫🇷</a> | <a href="#explanation-en">🇬🇧</a>
</p>

## <a name="explication-fr"></a>🇫🇷 Description
Philosophes est un projet du cursus de l'école 42 conçu pour initier aux concepts de programmation multi-threadée et de synchronisation des threads. Le projet simule le problème classique des "Philosophes attablés", où plusieurs philosophes doivent partager un nombre limité de fourchettes pour manger, penser et dormir sans provoquer de blocages ou de famine de ressources. Ce projet m'a plongé dans la gestion de processus concurrents, la sécurisation des threads et l'allocation efficace des ressources.

## Acquis d'apprentissage
Ce projet a été ma première expérience pratique avec la programmation multi-threadée, et il a éveillé un vif intérêt pour ce domaine. J'ai exploré les concepts suivants :
- **Création et gestion des threads** : Utilisation des threads POSIX (pthreads) pour créer et contrôler plusieurs threads représentant les philosophes.
- **Mutex pour la synchronisation** : Implémentation de mutex pour protéger les ressources partagées (fourchettes) et éviter les conditions de course.
- **Prévention des blocages et de la famine** : Conception d'une logique pour garantir que les philosophes accèdent aux fourchettes sans provoquer de blocages ou de famine de ressources.
- **Défis de la concurrence** : Compréhension des complexités liées à la coordination de plusieurs threads pour obtenir un comportement prévisible et sûr.

Ce projet a suscité une passion pour la programmation multi-threadée, m'incitant à l'explorer davantage dans des projets personnels où je continue d'étudier les techniques avancées de synchronisation et les modèles de programmation concurrente.

## Détails de l'implémentation
- **Langage** : C
- **Bibliothèques principales** : Threads POSIX (pthreads), bibliothèques standard C
- **Mécaniques principales** :
  - Chaque philosophe est un thread distinct.
  - Les fourchettes sont des ressources partagées, protégées par des mutex pour empêcher un accès simultané.
  - Un thread de surveillance s'assure qu'aucun philosophe ne meurt de faim ou ne décède par manque de ressources.
  - Le programme gère les paramètres d'entrée pour le nombre de philosophes, le temps pour mourir, manger, dormir et, optionnellement, le nombre de repas.
- **Défis relevés** :
  - Prévention des blocages en imposant un ordre d'acquisition cohérent des fourchettes.
  - Gestion de la synchronisation des threads pour éviter les conditions de course.
  - Optimisation des performances tout en garantissant la sécurité des threads.

## Utilisation
1. Clonez le dépôt.
2. Exécutez `make` pour compiler le projet.
3. Lancez le programme avec les arguments requis : `./philo <nombre_philosophes> <temps_mourir> <temps_manger> <temps_dormir> [nombre_repas]`.

Exemple : `./philo 5 800 200 200`.

## <a name="explanation-en"></a>🇬🇧 Overview
Philosophers is a project from the 42 school curriculum designed to introduce the concepts of multi-threaded programming and thread synchronization. The project simulates the classic "Dining Philosophers" problem, where multiple philosophers must share a limited number of forks to eat, think, and sleep without causing deadlocks or resource starvation. This project was a deep dive into managing concurrent processes, ensuring thread safety, and handling resource allocation efficiently.

## Learning Outcomes
This project was my first hands-on experience with multi-threaded programming, and it sparked a strong interest in the subject. I explored concepts such as:
- **Thread Creation and Management**: Using POSIX threads (pthreads) to create and control multiple threads representing philosophers.
- **Mutexes for Synchronization**: Implementing mutexes to protect shared resources (forks) and prevent race conditions.
- **Deadlock and Starvation Avoidance**: Designing logic to ensure philosophers can access forks without causing system deadlocks or resource starvation.
- **Concurrency Challenges**: Understanding the complexities of coordinating multiple threads to achieve predictable and safe behavior.

This project ignited a passion for multi-threaded programming, leading me to explore it further in personal projects where I continue to investigate advanced synchronization techniques and concurrent programming patterns.

## Implementation Details
- **Language**: C
- **Key Libraries**: POSIX threads (pthreads), standard C libraries
- **Core Mechanics**:
  - Each philosopher is a separate thread.
  - Forks are shared resources, protected by mutexes to prevent simultaneous access.
  - A monitoring thread ensures no philosopher starves or dies due to lack of resources.
  - The program handles input parameters for the number of philosophers, time to eat, time to sleep, and time to die.
- **Challenges Addressed**:
  - Preventing deadlocks by enforcing a consistent fork acquisition order.
  - Managing thread synchronization to avoid race conditions.
  - Optimizing performance while ensuring thread safety.

## Usage
1. Clone the repository.
2. Run `make` to compile the project.
3. Execute the program with the required arguments: `./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_meals]`.

Example : `./philo 5 800 200 200`.
