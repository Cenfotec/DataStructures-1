class Cola {
  constructor() {
    this.frente = {
      valor: null,
      sig: null
    };
    this.fin = {
      valor: null,
      sig: null
    };
    this.count = 0;
  }

  push(data) {
    let nodo = {
      valor: data,
      sig: null
    }

    if(this.isEmpty()) {
      this.frente = nodo;
      this.fin = nodo;
      this.frente.sig = this.fin;
      this.count++;
    }
    else {
      this.fin.sig = nodo;
      this.fin = nodo;
      this.count++;
    }
  }

  pop() {
    if(this.count > 1) {
      let nodo = this.frente;
      this.frente = this.frente.sig;
      this.count--;

      return nodo.valor;
    }
    else {
      let nodo = this.frente;
      this.frente = {
        valor: null,
        sig: null
      };
      this.fin = {
        valor: null,
        sig: null
      };
      this.count--;

      return nodo.valor;
    }

    return null;
  }

  next() {
    if(this.frente != null) {
      return this.frente.valor;
    }
  }

  size() {
    return this.count;
  }

  isEmpty() {
    if(this.frente != null){
      return !this.frente.valor;
    }
    return true;
  }
}

// const cola = new Cola();

// console.log('Tamaño inicial: ' + cola.size());

// cola.push('Daniel');
// cola.push('Pablo');
// cola.push('Sergio');

// console.log('Tamaño actual: ' + cola.size());
// console.log('Vacía: ' + cola.isEmpty());

// console.log(cola.next() + ' es el siguiente en la cola');
// console.log(cola.pop() + ' salió de la cola');

// console.log('Tamaño actual: ' + cola.size());
// console.log('Vacía: ' + cola.isEmpty());

// console.log(cola.next() + ' es el siguiente en la cola');
// console.log(cola.pop() + ' salió de la cola');
// console.log(cola.next() + ' es el siguiente en la cola');
// console.log(cola.pop() + ' salió de la cola');