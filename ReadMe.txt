Pour compiler ce programme, il faudra le faire à partir d'un système d'exploitation Windows sur lequel gcc
à été installer. Voici le lien d'une vidéo qui vous aidera pou l'installation : https://youtu.be/y-i96kqT53A.

Une fois que vous avez installer MinGW, lancer la commande suivante dans l'invite de commandes ( n'oublier pas 
de vous rendre dans le dossier dans lequel se trouve le code ) : gcc RansomWare.c -o ransom.exe

NE LE LANCEZ SURTOUT PAS DANS UN DOSSIER IMPORTANT, CELA RISQUE DE CHIFFRER VOS FICHIERS IMPORTANTS.

Déplacez le programme dans le dossier "test" dans lequel j'ai télécharger quelques images puis lancez-le.

Si vous voulez arrêter le programme par la suite, ouvrez un invite de commandes en tant qu'admnitrateur et 
exécutez la commande suivante : taskkill /f /im ransom.exe /t 

:)
