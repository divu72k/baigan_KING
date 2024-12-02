dict={}
lst=[]
inp="In the heart of the enchanted forest of Eldoria, where whispers of ancient magic danced through the leaves and mystical creatures roamed freely, there lived a young boy named Aiden. Aiden was an orphan, raised by the wise old wizard, Merlin, who had taken him in after finding him abandoned at the edge of the forest. From a young age, Aiden showed a remarkable affinity for magic. Under Merlin's tutelage, he honed his skills and learned to harness the powers of the elements. But there was one thing that eluded him - the legendary Crystal of Everlasting Light. Legends spoke of the Crystal as the source of all magic in the realm, imbued with the essence of the sun itself. It was said that whoever possessed the Crystal would wield unimaginable power and be able to bring balance to the world. Driven by a sense of destiny, Aiden embarked on a quest to find the Crystal of Everlasting Light. Armed with his magic staff and accompanied by his loyal companion, a wise old owl named Luna, he journeyed deep into the heart of the forest, braving perilous obstacles and encountering wondrous creatures along the way. As they traveled, Aiden and Luna faced trials of courage, wisdom, and strength. They navigated treacherous paths, crossed raging rivers, and outwitted cunning adversaries. But through it all, Aiden remained steadfast in his determination to find the Crystal and fulfill his destiny. Finally, after many days of travel, they reached the fabled Crystal Caverns, hidden deep beneath the roots of the oldest tree in Eldoria. Inside the caverns, the air shimmered with magic, and the walls glowed with an ethereal light. But guarding the Crystal was a fearsome dragon, its scales as hard as steel and its breath as hot as fire. Undeterred, Aiden stepped forward, his heart filled with courage and his mind focused on his goal. With Luna's guidance, Aiden unleashed his most powerful spells, weaving intricate incantations and summoning the elements to his aid. The cavern echoed with the clash of magic as Aiden and the dragon battled fiercely for control of the Crystal. At last, with a mighty roar, the dragon was vanquished, and Aiden stood victorious. With trembling hands, he reached out and grasped the Crystal of Everlasting Light, feeling its power course through him like a river of pure energy. As he held the Crystal aloft, a blinding light filled the cavern, illuminating every corner with its brilliance. And in that moment, Aiden understood the true meaning of magic - not just as a source of power, but as a force of harmony and creation. With the Crystal in his possession, Aiden returned to the surface, where he was hailed as a hero by the people of Eldoria. But he knew that his journey was far from over. With the Crystal as his guide, he vowed to use his newfound power to protect the realm and preserve the balance of magic for generations to come. And so, Aiden's legend lived on, his name whispered among the stars and his story told for centuries to come as a tale of bravery, adventure, and the enduring power of magic in the world."
inp1=inp.upper()
l=len(inp1)


for i in range(l):
    if inp1[i]==" ":
        continue
    else:
        lst+=inp1[i]

l2=len(lst)
for i in range(l2):
    if lst[i] not in dict:
        dict[lst[i]]=1
    else:
        dict[lst[i]]+=1
    


for i in range(65,91):
    char=chr(i)
    for key, value in dict.items():
        if key==char:
            print(key,"=",value)