Practico del Laboratorio 02

Nombre: Alex Ramiro Mendez Condori

Carrera: Ingenieria de Sistemas

Grupo: L1

HERENCIA Y POLIMORFISMO

Descripcion del trabajo:

En este código, la herencia se utiliza para compartir características y comportamientos comunes entre diferentes clases. Por ejemplo, la clase ANaveEnemigaCaza hereda de la clase ANaveEnemiga, lo que significa que ANaveEnemigaCaza obtiene todos los atributos y métodos de ANaveEnemiga. Esto evita la duplicación de código y permite la reutilización de funcionalidades comunes.

El polimorfismo se manifiesta en el código a través de la sobrescritura de métodos. Cuando una clase hereda de otra, puede sobrescribir los métodos de la clase base con implementaciones específicas para la clase derivada. Por ejemplo, en las clases ANaveEnemigaCazaG1 y ANaveEnemigaCazaG2, se sobrescriben los métodos Mover, Disparar, Destruirse, Atacar, etc., para proporcionar comportamientos específicos para cada tipo de nave enemiga. Esto permite tratar a objetos de clases derivadas como objetos de la clase base, pero con comportamientos específicos según su tipo.

La clase abstracta se utiliza para definir una interfaz común sin proporcionar una implementación concreta para uno o más métodos. En este código, la clase ANaveEnemiga se declara como una clase abstracta con los métodos Mover, Disparar, Destruirse, Atacar, etc., marcados como funciones puras virtuales. Esto significa que las clases derivadas deben proporcionar una implementación para estos métodos, lo que garantiza que todas las clases derivadas tengan ciertos comportamientos comunes, pero cada una puede implementarlos de manera diferente según sea necesario.

Este ejemplo con ANaveEnemiga y sus clases derivadas tambien se aplica de una manera muy similar en las otras clases como ANaveEnemigaTranporte, ANaveEnemigaEspia, ANaveEnemigaReabastecimiento, etc.
