//
//  ensembleIpl.h
//  
//
//  Devoir fait par
//     Coéquipier 1 :
//     Coéquipier 2 :
//

// Documentation à fournir concernant la méthode "insere"
// complétez en précisant votre interprétation des conditions. Quel est le cas général ?
//
// Cas 1 :
// cas ou l'iterateur ne pointe pas vers la fin et que le contenu de la cellule pointée par
// l'itérateur est plus petit ou egal a la valeur a inserer.
// dans ce cas la , on sait que la valeur est apres ou egal l'itérateur, mais il faut verifier son existence
// Cas 2 :
// soit l'iterateur pointe sur la fin
// OU l'iterateur ne pointe pas vers la fin et la valeur a inserer est plus petite que celle pointé par l'itérateur
// dans ce cas si, on verifie si avant est le debut.
// si on est au debut, on sait qu'on doit avancer
// Cas 3 :
// memes condtions que 2, sauf que avant n'est le debut.
// dans ce cas la, si la valeur avant est plus grande que la valeur a inserer
// si oui,
// Cas 4 :
//
// Le cas général est le no. 4


/////////////////////////////////////////////////////////////////
// copieur et destructeur de liste

template <typename TYPEContenu>
ensemble<TYPEContenu>::ensemble(const ensemble<TYPEContenu>& e_ensSrc)
    : ensemble()
{
    // a completer

    cellule* iACopier = e_ensSrc.m_avant->m_suiv[0];
    cellule* i=m_avant;
    ensemble<TYPEContenu>::iterateur it =this->begin();
    while (iACopier->m_suiv[0]!=nullptr) {
        this->insere(it,*iACopier->m_contenu);
        iACopier=iACopier->m_suiv[0];
    }

}

template <typename TYPEContenu>
ensemble<TYPEContenu>::~ensemble()
{

    //on utilise nettoie et supprime les cellules de debut et fin
    nettoie();
    delete m_avant->m_suiv[0];
    delete m_avant;

}

/////////////////////////////////////////////////////////////////
// localise un element, retourne la fin si absent

template <typename TYPEContenu>
typename ensemble<TYPEContenu>::iterateur ensemble<TYPEContenu>::trouve(const TYPEContenu& e_contenu) const
{
    // a completer
    TYPEContenu i=borneSup(e_contenu);
    if (!(e_contenu<i)&&!(i<e_contenu)) {
        return i;
    }
    return nullptr;
}

// localise la premiere position ou l'element n'est
// pas plus petit que celui recu en parametre

template <typename TYPEContenu>
typename ensemble<TYPEContenu>::iterateur ensemble<TYPEContenu>::borneInf(const TYPEContenu& e_contenu) const
{

    // code fonctionnel mais non optimal. a remplacer

    cellule *c = m_avant;
    cellule *apres = m_avant->m_prec[0];
    size_t n=m_avant->m_suiv.size();
    for (size_t i=n;i>0;i--) {
        while ((c->m_suiv[i-1]->m_contenu!=nullptr)&&(*c->m_suiv[i-1]->m_contenu<e_contenu))
            c=c->m_suiv[i-1];
    }
    return iterateur(c->m_suiv[0]);
    
}

template <typename TYPEContenu>
typename ensemble<TYPEContenu>::iterateur ensemble<TYPEContenu>::borneSup(const TYPEContenu& e_contenu) const
{
    // a completer
    cellule *c = m_avant;
    cellule *apres = m_avant->m_prec[0];
    size_t n=m_avant->m_suiv.size();
    for (size_t i=n;i>0;i--) {
        while ((c->m_suiv[i-1]->m_contenu!=nullptr)&&!(e_contenu<c->m_suiv[i-1]->m_contenu))
            c=c->m_suiv[i-1];
    }
    return iterateur(c->m_suiv[0]);
}

/////////////////////////////////////////////////////////////////
// elimine val de l'ensemble, si present

template <typename TYPEContenu>
size_t ensemble<TYPEContenu>::retire(const TYPEContenu& e_contenu)
{
    iterateur i= trouve(e_contenu);
    if (i!=nullptr) {
        return enleve(i);
    }

    return 0;
}

// elimine de l'ensemble l'element en position it

template <typename TYPEContenu>
typename ensemble<TYPEContenu>::iterateur ensemble<TYPEContenu>::enleve(iterateur e_iter)
{
    // a completer
}
