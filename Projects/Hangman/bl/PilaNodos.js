class Pila {
  constructor() {
    this.tope = {
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

    nodo.sig = this.tope;
    this.tope = nodo;
    this.count++;
  }

  pop() {
    if(!this.isEmpty()) {
      let nodo = this.tope;
      this.tope = this.tope.sig;
      this.count--;

      return nodo.valor;
    }

    return null;
  }

  top() {
    return this.tope.valor;
  }

  size() {
    return this.count;
  }

  isEmpty() {
    return !this.tope.valor;
  }
}

// const pila = new Pila();

// console.log('Tamaño inicial: ' + pila.size());

// pila.push('Daniel');
// pila.push('Pablo');
// pila.push('Sergio');

// console.log('Tamaño actual: ' + pila.size());
// console.log('Vacía: ' + pila.isEmpty());

// console.log(pila.top() + ' está arriba de la pila');
// console.log(pila.pop() + ' salió de la pila');
// console.log(pila.top() + ' está arriba de la pila');
// console.log(pila.pop() + ' salió de la pila');
// console.log(pila.top() + ' está arriba de la pila');
// console.log(pila.pop() + ' salió de la pila');
// console.log(pila.pop() + ' salió de la pila');

// console.log('Tamaño actual: ' + pila.size());
// console.log('Vacía: ' + pila.isEmpty());