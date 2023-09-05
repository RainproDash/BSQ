# BSQ
__Trouver le plus grand carré__

Le but de ce programme est de trouver le plus grand carré possible sur un plateau tout en évitant les obstacles.

Le tableau peut être généré de deux manières. La première consiste à lire un fichier passé en argument du programme.

Le fichier est valide s'il respecte ces contraintes :

  - sa première ligne contient le nombre de lignes du tableau (et seulement celui-là)
  - "." (représentant une place vide) et « o » (représentant un obstacle) sont les deux seuls caractères possible des autres lignes
  - toutes les lignes sont de même longueur (sauf la première)
  - il contient au moins une ligne
  - chaque ligne se termine par '\n'

Le programme affiche le tableau, avec quelques "." remplacé par « x » pour représenter le plus grand carré trouvé.

![image](https://github.com/RainproDash/BSQ/assets/91848714/3af3df05-88aa-41d9-9f04-40223b437665)

![image](https://github.com/RainproDash/BSQ/assets/91848714/66f664ce-255c-43d3-9e7e-18802609c668)

Oui c'est bien un carré même si ça n'en a pas l'air !


La deuxième façon d'obtenir une plateau est d'en générer un en fonction de paramètres donnés.

Les paramètres sont un nombre, représentant la largeur et la hauteur du plateau, et un motif qui sera répété ligne par ligne le long du plateau.

Le programme affiche le tableau résolu.

![image](https://github.com/RainproDash/BSQ/assets/91848714/1ead49e4-0cc4-44c5-902c-4bad2206641b)
