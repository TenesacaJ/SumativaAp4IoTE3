import { Component } from '@angular/core';
import { PokeApiService } from '../Servicio/poke-api.service';
import { Firestore } from '@angular/fire/firestore';
import { doc, setDoc } from 'firebase/firestore';


@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage {

  pokemonName: string="";
  namePokemon: any;
  pokemonTypes: string[] = [];
  ruta: any;

  constructor(private api: PokeApiService, private db:Firestore) {}

  // Objeto que mapea los tipos de Pokémon a sus colores
  typeColors: any = {
    steel: '#60A2B9',
    water: '#2481F0',
    bug: '#97A61D',
    dragon: '#4F60E2',
    electric: '#FAC100',
    ghost: '#6F3F70',
    fire: '#E62223',
    fairy: '#EF70F0',
    ice: '#3DD9FF',
    fight: '#FF8100',
    normal: '#A0A2A0',
    grass: '#3DA224',
    psychic: '#EF3F7A',
    rock: '#AFAA81',
    dark: '#4E3F3C',
    ground: '#914F1A',
    poison: '#913ECB',
    flying: '#82BAF0'
  };

  async getPokemonByName() {
    this.api.getPokemonName(this.pokemonName).subscribe(async (data) => {
      this.namePokemon = data;
      this.pokemonTypes = this.namePokemon.types.map((type: any) => type.type.name);
      const pokemonType = data.types[0].type.name;

      // Llama al método para enviar el tipo del Pokémon a Firestore
      await this.sendPokemonTypeToFirestore(pokemonType);
    });
  }

  getTypeColor(type: string): string {
    // Devuelve el color correspondiente para cada tipo de Pokémon
    return this.typeColors[type.toLowerCase()] || 'gray'; // Si no se encuentra un color, se utiliza 'gray' como valor predeterminado
  }

  async sendPokemonTypeToFirestore(pokemonType: string) {
    const pokemonRef = doc(this.db, "Pokedex", "Pokemon");
    await setDoc(pokemonRef, { Tipo: pokemonType });
    console.log("Tipo de Pokémon enviado a Firestore correctamente.");
  }  
}
