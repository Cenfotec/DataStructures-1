class Lista {
  constructor() {
    this.cabeza = {
      valor: null,
      sig: null
    };
    this.count = 0;
  }

  add(data) {
    let nodo = {
      valor: data,
      sig: null
    }

    if(this.isEmpty()){
      this.cabeza = nodo;
    }
    else {
      let aux = this.cabeza;
      while(aux.sig != null) {
        aux = aux.sig;
      }
      aux.sig = nodo;
    }
    this.count++;
  }

  search(data) {
    let aux = this.cabeza;
    let pos = 0;

    while(aux != null && aux.valor != null) {
      if(aux.valor === data){
        return pos;
      }
      aux = aux.sig;
      pos++;
    }

    return null;
  }

  delete(data) {
    let pos = this.search(data);
    if(pos != null) {
      if(pos === 0) {
        let aux = this.cabeza;
        this.cabeza = this.cabeza.sig;
        //delete aux;
        this.count--;
        return true;
      }
      else {
        let ant = this.cabeza;
        let act = this.cabeza.sig;
        for(let i = 1; i < pos; i++){
          ant = ant.sig;
          act = act.sig;
        }
        ant.sig = act.sig;
        //delete act;
        this.count--;
        return true;
      }
    }

    return false;
  }

  size() {
    return this.count;
  }

  isEmpty() {
    return !this.cabeza.valor;
  }

  get(pos) {
    let aux = this.cabeza;
    let cont = 0;

    if(pos < this.count) {
      for(cont; cont < pos; cont++) {
        aux = aux.sig;
      }
      return aux.valor;
    }
    return null;
  }

  print() {
    let aux = this.cabeza;
    let salida = '';

    if(!this.isEmpty()) {
      while(aux != null && aux.valor != null) {
        salida += aux.valor + ' ';
        aux = aux.sig;
      }
      return salida;
    }
    return null;
  }
}

// const lista = new Lista();

// console.log('Vacía: ' + lista.isEmpty());
// console.log('Tamaño inicial: ' + lista.size());

// lista.add('Daniel');
// lista.add('Pablo');
// lista.add('Sergio');

// console.log('Tamaño actual: ' + lista.size());
// console.log('Vacía: ' + lista.isEmpty());

// console.log('Daniel se encuentra en la posición: ' + lista.search('Daniel'));
// console.log('Pablo se encuentra en la posición: ' + lista.search('Pablo'));
// console.log('Sergio se encuentra en la posición: ' + lista.search('Sergio'));

// console.log('Pos 0: ' + lista.get(0));
// console.log('Pos 1: ' + lista.get(1));
// console.log('Pos 2: ' + lista.get(2));
// console.log('Pos 3: ' + lista.get(3));

// console.log(lista.delete('Daniel'));
// console.log('Tamaño actual: ' + lista.size());
// console.log('Daniel se encuentra en la posición: ' + lista.search('Daniel'));
// console.log('Pablo se encuentra en la posición: ' + lista.search('Pablo'));
// console.log('Sergio se encuentra en la posición: ' + lista.search('Sergio'));

// console.log(lista.print());