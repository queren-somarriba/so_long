# So_long

So_long est un projet en C utilisant la bibliothèque `mlx` pour créer un petit jeu 2D basé sur un labyrinthe. L'objectif est de déplacer un personnage sur une carte afin de collecter des objets et atteindre une sortie.

## Installation

Pour compiler `so_long`, utilisez la commande suivante :

```sh
gcc -Wall -Wextra -Werror so_long.c utils/*.c -lmlx -framework OpenGL -framework AppKit -o so_long
```

## Utilisation

La syntaxe de `so_long` est la suivante :

```sh
./so_long map.ber
```

- `map.ber` : Fichier contenant la carte du jeu au format `.ber`.

Exemple :

```sh
./so_long map/level1.ber
```

## Règles du jeu

- Le joueur peut se déplacer avec les touches `W`, `A`, `S`, `D`.
- Il doit collecter tous les objets (`C`) avant de pouvoir atteindre la sortie (`E`).
- Les murs (`1`) bloquent les déplacements.
- L'espace vide est représenté par `0`.
- Le joueur est représenté par `P`.

### Exemple de carte

```
11111
1P0C1
1C0E1
11111
```

## Bonus : Améliorations supplémentaires

La version bonus ajoute les fonctionnalités suivantes :

### Mouvements animés
- Ajout d’animations pour le personnage lors des déplacements.
- Effets visuels pour une meilleure immersion.

### Ennemis
- Ajout d’ennemis qui se déplacent sur la carte et poursuivent le joueur.
- Si un ennemi attrape le joueur, la partie est perdue.

### Compteur de mouvements
- Affichage du nombre de déplacements effectués par le joueur.
- Objectif : terminer le niveau en un minimum de coups.

### Support de plusieurs cartes
- Possibilité de charger différents niveaux en modifiant le fichier `.ber`.
