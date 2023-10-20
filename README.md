# Cub3d

Cub3D est un projet de la partie obligatoire du cursus. Il est uniquement réalisé en C et l'objectif principal était de recréer le premier FPS, Wolfenstein 3D. Ce jeu utilise le rendu raycasting pour créer une illusion 3D.


## Fonctionnement

Il vérifiera d'abord l'arguments :
 
  - le fichier map avec toutes les informations de configuration (obligatoire)
     
Le programme analysera ensuite le fichier de configuration, initiera plusieurs structures avec les informations du joueur et chargera les textures/sprites. Ensuite, il rafraîchira continuellement l'écran grâce à un algorithme de raycasting, créant une image différente à chaque fois que le joueur bouge/tourne/puvre une porte...


## Raycasting 

Le Raycasting est une technique de rendu permettant de créer une perspective 3D dans une carte 2D. À l'époque où les ordinateurs étaient plus lents, il n'était pas possible d'exécuter de vrais moteurs 3D en temps réel, et le raycasting était la première solution. Le raycasting peut aller très vite, car seul un calcul doit être effectué pour chaque ligne verticale de l'écran. Le jeu le plus connu ayant utilisé cette technique est bien sûr Wolfenstein 3D.
Pour effectuer mes calculs de raycasting, j'ai utilise ce tuto : https://lodev.org/cgtutor/raycasting3.html



## Commandes

|Action |CLÉ|
|---|---|
|ESC ou ❌|fermer le jeu|
|A| aller à gauche|
|D |aller à droite|
|W| avancer|
|S| reculer|
|Esp| ouvrir une porte|
|→ |tourner à droite|
|← |tourner à gauche|
|mouse|regarder autour|

## Aperçu

![recording-2023-10-20-19-07-58](https://github.com/Maxime2i/Cub3d/assets/43725047/efb7b6b0-b856-4639-9844-d83ecc84efa1)
