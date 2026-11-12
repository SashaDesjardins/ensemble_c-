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
//l'iterateur n'est pas a la fin et on est apres le bon endroit pour inserer
// Cas 2 :
//soit l'ensemble est vide ou on insere la plus petite valeure de l'ensemble au debut
// Cas 3 :
// nous ne sommes ni au debut ni a la fin, et on essaie d'inserer la valeur au bon endroit
// OU, insertion a la fin de la plus grande valeur de l'ensemble
// Cas 4 :
// cas restant, ou on est ni au debut, ni a la fin, mais avant la valeur a inserer
// OU a la fin, avant
// Le cas général est le no. 3


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
    iterateur i=borneInf(e_contenu);
    if (!(e_contenu<*(i.m_pointeur->m_contenu))&&!(*(i.m_pointeur->m_contenu)<e_contenu)) {
        return i;
    }
    return m_avant->m_prec[0];
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
        while ((c->m_suiv[i-1]->m_contenu!=nullptr)&&!(e_contenu<*(c->m_suiv[i-1]->m_contenu)))
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
        enleve(i);
        return 1;
    }

    return 0;
}

// elimine de l'ensemble l'element en position it

template <typename TYPEContenu>
typename ensemble<TYPEContenu>::iterateur ensemble<TYPEContenu>::enleve(iterateur e_iter)
{
    // a completer
    size_t n = e_iter.m_pointeur->m_prec.size();
    for (int i=0;i<n;i++) {
        e_iter.m_pointeur->m_suiv[i]->m_prec[i]=e_iter.m_pointeur->m_prec[i];
        e_iter.m_pointeur->m_prec[i]->m_suiv[i]=e_iter.m_pointeur->m_suiv[i];
        e_iter.m_pointeur->m_prec[i]=nullptr;
        e_iter.m_pointeur->m_suiv[i]=nullptr;
    }
    e_iter.m_pointeur->m_contenu=nullptr;
    delete e_iter.m_pointeur->m_contenu;
    delete e_iter.m_pointeur;
    m_taille--;
    return e_iter;
}
