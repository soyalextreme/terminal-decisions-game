#include <iostream>

using namespace std;



// GLOBAL VARIABLES
bool game_on = true;
int chapter = 0;
string decision_tree = "";




string print_dialog(string options [], string options_values [], string history, int a_size ){
    // PRINTS AND RETURNS A RESPONSE FOR THE INPUT OF THE USER
    cout << history << endl;
    for (int i=0; i < a_size; ++i){
        cout << options[i] << "  " << options_values[i] << endl;
    }
    string response = "";

    cin >> response;
    cout << "*******************************************************" << endl;
    return response;
}


bool process_action(string options [], int a_size, string player_input, string options_actions [], string msg_action){
    // IN BASE OF SOME OPTIONS TRIGERS DE ACTIONS AND CHANGE THE CHAPTER
    bool game_on = true;

    for(int i = 0; i < a_size; ++i){
        if(options[i] == player_input){
            if(options_actions[i] == "QUIT")
            {
                // eleccion incorrecta Game Over!!
                cout << "GAME OVER!" << " " << msg_action << endl;
                game_on = false;
            }else if(options_actions[i] == "WIN"){

                cout << "GANASTE" << " " << msg_action << endl;
                game_on = false;
            }
            else
            {
                cout << options_actions[i] << endl;
                ++chapter;
            }
            break;
        }
    }
    return game_on;
}


void start_chapter(int n_options, string options [], string options_values [], string options_actions [], string history, string msg_action){
    // GENERATES A CHAPTER AND TRIGGERS THE OTHER FUNCTIONS
    string player_input = print_dialog(options, options_values, history, n_options);
    game_on = process_action(options, n_options, player_input, options_actions, msg_action);
    decision_tree = player_input;
}


void manage_chapters(){
    // MANAGE THE CHAPTERS AND DIFERENT DECISION TREE
    switch(chapter){
            case 0:
            {
                int n_options = 2;
                string options [n_options]= {"s", "q"};
                string options_values [n_options] = {"Lets begin the game","Exit"};
                string options_actions [n_options] = {"'Personaje abriendo los ojos'", "QUIT"};
                string history = "Hospital Zombie\n Juego de consola de desiciones!\n Alejandro Andrade Soriano";
                start_chapter(n_options, options, options_values, options_actions, history, "Espero pronto te atrevas a jugarlo!");
                break;
            }
            case 1:
            {
                int n_options = 2;
                string options [n_options]= {"a", "b"};
                string options_values [n_options] = {"Ir Al bano", "Dormirme otro Rato"};
                string options_actions [n_options] = {"Bien te levantaste y fuiste al bano", "QUIT"};
                string history = "Despiertas en una sala de un hospital abandonado postrado sobre una camilla \n que decides hacer?";
                start_chapter(n_options, options, options_values, options_actions, history, "Te jalan de los pies mientras duermes, te COMEN VIVO!");
                break;
            }
            case 2:
            {
                string history = "Observas en el bano un gran rastro de sangre en todo el piso y espejo\n que decides hacer?";
                int n_options = 3;
                string options [n_options] = {"a", "b", "c"};
                string options_values [n_options] = {"Buscar algo en los cajones del bano", "tratar de limpiar el espejo", "salir del bano y de la habitacion en busca de algo"};
                string options_actions [n_options] = {"Perfecto no tiene llave los cajones", "QUIT", "Sales del bano espantado por la sangre y te diriges afuera de la habitacion"};
                start_chapter(n_options, options, options_values, options_actions, history, "una figura aparece detras de ti por el espejo y te muerde el cuello!");
                break;
            }
            case 3:
            {
                if(decision_tree == "a"){
                    string history = "En el cajon encontraste una linterna.. debe haber algo mas\n que decides hacer?";
                    int n_options = 2;
                    string options [n_options] = {"a", "b"};
                    string options_values [n_options] = {"Seguir buscando en el cuarto algo debe haber", "Salir de el cuarto para buscar la salida!"};
                    string options_actions [n_options] = {"Extranamente encuentras una pistola en el bote de basura del bano", "Al salir y ver con la linterna ves que una sombra se mueve"};
                    start_chapter(n_options, options, options_values, options_actions, history, "" );
                    break;

                }else{
                    string history = "Al salir de el cuarto te das cuenta que no hay luz en el hospital completo\n que decides hacer?";
                    int n_options = 2;
                    string options [n_options] = {"c", "d"};
                    string options_values [n_options] = {"Regresar a buscar algo en el bano", "Tratar de seguir y buscar una salida en la obscuridad"};
                    string options_actions [n_options] = {"Regresas al cuarto y decides buscar algo en el bano", "QUIT"};
                    start_chapter(n_options, options, options_values, options_actions, history, "No sientes de donde pero te empiezan a comer VIVO!");
                    break;
                }
            }
            case 4:
            {
                if(decision_tree == "a"){
                    string history = "Decides salir del cuarto con la pistola y la linterna al caminar por el pasillo principal te encuentras con un zombie y sorpresa\n Es tu mejor amigo es un zombie que se acerca a comerte!.\n que decides hacer?";
                    int n_options = 2;
                    string options [n_options] = {"a", "b"};
                    string options_values [n_options] = {"Pegarle un tiro con todo el dolor de tu corazon", "Dejarte comer no tienes el valor de matar a tu mejor amigo! Espera claro es un muerto ya."};
                    string options_actions [n_options] = {"Despues del increible sonido del disparo y la sangre en tu rostro corres por el pasillo principal saliendo a un mundo donde todo o casi todo el mundo es zombie", "Despues de una mordida de quien era tu mejor amigo te escondes solo para darte cuenta que tiempo despues te convertiras en zombie"};
                    start_chapter(n_options, options, options_values, options_actions, history, "");
                    break;
                }else if(decision_tree == "b"){
                    string history = "No te da confianza continuar a buscar la salida!";
                    int n_options = 2;
                    string options [n_options] = {"c", "d"};
                    string options_values [n_options] = {"Regresar al bano creo que habia una arma para defenderme", "Continuar no tienes miedo a nada!"};
                    string options_actions [n_options] = {"Regresas al cuarto y decides buscar algo en el bano", "QUIT"};
                    start_chapter(n_options, options, options_values, options_actions, history, "No sientes de donde pero te empiezan a comer VIVO!");
                    break;
                }else if(decision_tree == "c"){
                    string history = "Encuentras una pistola en el bote de basura y una linterna en el cajon.\n que decides hacer?";
                    int n_options = 2;
                    string options [n_options] = {"d", "e"};
                    string options_values [n_options] = {"Salir listo para matar lo que sea", "Pegarte un tiro y acabar con tu sufrimiento"};
                    string options_actions [n_options] = {"Al salir ya no hay nada en el pasillo! Ufff cerca", "QUIT"};
                    start_chapter(n_options, options, options_values, options_actions, history, "Esa no es una opcion eres valiente!");
                    break;
            }
            case 5:
            {
                if(decision_tree == "a"){
                    string history = "Sales de el hospital para darte cuenta de que es un mundo zombie.\n QUE HABRA PASADO?";
                    int n_options = 1;
                    string options [n_options] = {"q"};
                    string options_values [n_options] = {"Gracias por Jugar\n Autor Alejandro Andrade Soriano\n Presiona q para salir"};
                    string options_actions [n_options] = {"WIN"};
                    start_chapter(n_options, options, options_values, options_actions, history, "Comparte con tus amigos");
                    break;
                }else if(decision_tree == "b"){
                    string history = "Estas a minutos de volverte zombie\n que decides hacer?";
                    int n_options = 2;
                    string options [n_options] = {"a", "b"};
                    string options_values [n_options] = {"Pegarte un tiro", "Cerrar tus ojos y dormir, tendra que pasar"};
                    string options_actions [n_options] = {"WIN", "WIN"};
                    start_chapter(n_options, options, options_values, options_actions, history, "Eres la persona mas leal que conozco Gracias por jugar mi juego!\n Te invito a probar los demas finales\n Alejandro Andrade");
                    break;
                }else if(decision_tree == "c"){
                    // regresando al capitulo anterior
                    chapter = 3;
                    decision_tree = "a";
                }else{
                    string history = "Al salir del hospital te das cuenta de que el mundo no es el mismo! Recuerdas que tu amigo estaba en el mismo hospital.\n Que le habra pasado?";
                    int n_options = 2;
                    string options [n_options] = {"q"};
                    string options_values [n_options] = {"Listo! Terminaste el juego sin derramar una gota de sangre con la pistola\n Presiona q para salir"};
                    string options_actions [n_options] = {"WIN"};
                    start_chapter(n_options, options, options_values, options_actions, history, "Gracias por Jugar mi juego!\n Alejandro Andrade Soriano");
                    break;
                }
            }
        }
    }
}




int main()
{
    // MAIN HISTORY CICLE
    while(game_on){
        manage_chapters();
    }
    return 0;
}
