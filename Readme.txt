	Balan Giorgiana-Lavinia
		331CB

				 Tema 1 EGC


	In functia "Init" am apelat pentru inceput functiile necesare pentru camera.
Urmeaza, apoi, toate initializarile factorilor pe care i-am folosit in restul 
programului si obiectele din scena realizate din vertecsi si indecsi si 
construite cu ajutorul functiei CreateMesh din laboratorul 2. Astfel, in functia 
"Init" am construit pasarea, o aripa a acesteia, un turn si meshe pentru iarba 
si munte pentru a face scena cat mai realista.
	In plus, in "Init", la construirea pasarii am retinut si pozitiile minime 
si maxime pe axele Ox si Oy ale pasarii, ceea ce imi va fi util la realizarea 
coliziunilor cat mai precise si la verificarile parasirii scenei de catre pasare.

	In "Update", am implementat functionalitatile cerute in tema plus cate ceva 
din bonusurile propuse. 
	Aici am randat pasarea scalata si translatata in mijlocul ecranului si, 
deci, am actualizat pozitiile minime si maxime intre care se afla corpul 
pasarii pe Ox si Oy. De asemenea, am mai realizat o translatare pe Oy cu factorul 
translateYbird prin care realizez animatiile pasarii. Acest factor de translatie 
pe Oy a pasarii depinde de un alt factor si anume, acceleration, pe care il 
resetez la fiecare apasare a tastei space si il scad progresiv pentru o animatie 
lenta care sa simuleze caderea pasarii. Pe langa toate aceste transformari 
aplicate pasarii mai aplic si o rotatie care, de fapt, este prima transformare 
aplicata astfel incat pasarea sa se roteasca in jurul propriului centru de 
greutate (aproximativ) intrucat initial, construiesc pasarea cu centrul 
aproximativ in originea sistemului de coordonate. Prin aceasta rotatie am realizat 
animatiile conform carora pasarea isi ridica ciocul in sus cand urca (la apasarea 
tastei space) sau se roteste in jos cand coboara din cauza gravitatiei.
Unghiul cu care realizez rotatia depinde, de asemenea, de un factor pe care 
il resetez la apasarea tastei space si il micsorez progresiv, tot pentru ca 
animatiile de rotire sus-jos sa nu fie bruste. 
	In functia "Update" randez aripa pasarii, care sufera cam aceleasi transformari 
ca si pasarea, cu mici modificari la unghiul de rotire pe care l-am setat in asa 
fel incat sa arate cat de cat natural pozitia aripii. O alta modificare este la 
transformarea de scalare, intrucat am facut ca aripa sa fie in pozitia sus(initiala) 
atunci cand pasarea coboara sau pe langa corpul pasarii(jos) atunci cand urca, deci, 
tot in functie de factorul acceleration. Astfel am realizat animatia pentru modul 
in care pasarea da din aripi.
	Tot in functia "Update" am facut verificarile conform carora pasarea ar iesii 
din ecran, caz in care jocul se incheie si afisez scorul obtint.
	Mai departe, am randat cate doua perechi de turnuri per ecran, unul normal 
si unul invers, fiecare pereche, respectiv fiecare turn din pereche avand factorul 
corespunzator de scalare pe Oy, functionalitate pe care am realizat-o cu ajutorul 
unei functii de randomizare. Pentru fiecare din cele 4 turnuri de pe ecran fac 
verificarile necesare de coliziune, iar dupa trecerea cu succes de fiecare pereche 
de turnuri incrementez scorul. Dupa parasirea unei perechi de turnuri a ecranului 
o randez din nou la final cu altii factori de scalare pe Oy.
	Inca o functionalitate implementata in "Update" este cresterea dificultatii 
jocului odata cu cresterea scorului jucatorului. Astfel, la atingerea scorului 15 
viteza de deplasarea a turnurilor catre stanga se mareste. La fel si la 30, de 
unde ramane constant pentru a nu face jocul imposibil. 
	La finalul functiei, randez iarba si muntele scalate corespunzator. 

	In incheiere, pentru aceasta tema, am implementat toate functionalitatile 
cerute in enunt, plus din bonus: am facut scena sa arate cat mai realist (atat 
decorul cat si pasarea in sine), am crescut dificultatea jocului pe masura 
cresterii scorului jucatorului si am realizat animatia care sa simuleze modul 
in care pasarea da din aripi.