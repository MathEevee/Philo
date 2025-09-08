# 🍽️ philosopher

Le programme doit gérer des cycles de "vie".

La vie d'un philosophe est de penser, manger et dormir.

Le philosophe a besoin de deux "fourchettes" pour manger, ils en ramènent chacun une. La difficulté est de gérer le "partage" pour ne pas faire de data race ou de duplication de données créer par les fonctions de thread.

## 📷 Schéma

<img width="290" height="267" alt="Screenshot from 2025-09-08 11-56-49" src="https://github.com/user-attachments/assets/08aedf49-5f20-4026-8426-656f99e46e14" />

🟦 : Philosophe
🟪 : Fourchette


Le but est de savoir si les cycles avec les temps donnés et le nombre de philosophe fonctionnent :

- soit la simulation réussit et continue à l'infini ✅

- soit elle s'arrête car le nombre de repas donnés a été atteint par tous les philosophes ✅

- soit un philosophe "meurt" et la simulation s'arrête ❌

On doit générer un thread par philosophe, ils ne doivent pas communiquer entre eux pour savoir si une fourchette est prise ou si un philosophe est mort.

---

## 🚀 Lancer le programme

1. **Compiler** le programme :
   ```bash
   cd philo
   make
   ```

2. **Exécuter** le programme :
   ```bash
   1. ./philo <nbr de philo> <temps pour mourir> <temps de repas> <temps de sommeil>
   2. ./philo <nbr de philo> <temps pour mourir> <temps de repas> <temps de sommeil> <nbr de repas>

   exemple : 1. ./philo 5 800 200 200 ✅
             2. ./philo 5 800 200 200 20 ✅
   ```

---

