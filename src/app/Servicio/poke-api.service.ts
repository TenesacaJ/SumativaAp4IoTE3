import { HttpClient } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class PokeApiService {

  private apiUrl = 'https://pokeapi.co/api/v2/';

  constructor(private http: HttpClient) { }

  getPokemonName(name: string): Observable<any> {
    // Utiliza el método get del HttpClient para realizar una solicitud GET a la URL de la PokeAPI con el nombre del Pokémon.
    return this.http.get(this.apiUrl + "pokemon/" + name);
  }
}
